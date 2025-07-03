#!/bin/bash

set -e  # Arrête le script en cas d'erreur
set -o pipefail

# Liste des projets à fusionner
projects=(
)

# Branche à importer (commune à tous tes projets)
branch="main"

# Chemin de base pour les remotes
github_user="v-blanc"
github_base="git@github.com:$github_user"

# Tu dois déjà être dans le dossier de 42cursus
echo ">> Dépôt principal : $(pwd)"

for project in "${projects[@]}"; do
  echo "🔄 Fusion du projet $project"

  remote_name="${project}_remote"
  temp_branch="${project}_temp"
  remote_url="$github_base/$project.git"

  # 1. Ajoute le remote
  git remote add "$remote_name" "$remote_url"

  # 2. Fetch
  git fetch "$remote_name"

  # 3. Crée une branche temporaire
  git checkout -b "$temp_branch" "$remote_name/$branch"

  # 4. Crée un sous-dossier et déplace les fichiers dedans
  mkdir -p "$project"
  git ls-tree -z --name-only HEAD | xargs -0 -I{} git mv {} "$project/" 2>/dev/null || true

  # 5. Commit du déplacement
  git commit -m "Déplacement du projet $project dans $project/"

  # 6. Retour sur main et merge avec historique
  git checkout main
  git merge --allow-unrelated-histories "$temp_branch" -m "Fusion du projet $project avec son historique"

  # 7. Nettoyage
  git branch -d "$temp_branch"
  git remote remove "$remote_name"

  echo "✅ $project fusionné avec succès"
done

echo "🚀 Tous les projets ont été fusionnés !"
echo "👉 Tu peux maintenant : git push origin main --force"

