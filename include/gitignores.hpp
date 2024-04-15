// Licensed under GPL 3.0 -- full license text in file LICENSE
#ifndef GITIGNORES_HPP
#define GITIGNORES_HPP

#include <string>

const std::string cpp_gitignore_template = R"(# Objects
*.o
*.obj
*.a
*.lib

# Executables and symbol tables
*.exe
*.out
*.dll
*.so
*.dylib
*.bin
*.run
*.elf

# DB data
*.log
*.tlog
*.idb
*.pdb
*.opendb

# Developer prefs
.vscode/
.idea/
*.sln
*.suo
*.user
*.userprefs
*.vcxproj
*.vcxproj.filters
*.vcxproj.user

# Temp files
*.tmp
*.temp
*.bak
*.swp

# Compiler temp files
Build/
build/
bin/
obj/
Logs/
DerivedData/

# wha is this?
.DS_Store
Thumbs.db
)";

const std::string c_gitignore_template = cpp_gitignore_template;

const std::string python_gitignore_template = R"(# Byte-compiled / optimized files
__pycache__/
*.py[cod]

# C extensions
*.so

# Developer prefs
.vscode/
.idea/
*.sln
*.suo
*.user
*.userprefs
*.vcxproj
*.vcxproj.filters
*.vcxproj.user

# Distribution / packaging
.Python/
build/
develop-eggs/
dist/
downloads/
eggs/
.eggs/
lib/
lib64/
parts/
sdist/
var/
*.egg-info/
.installed.cfg
*.egg

# PyInstaller
#  Usually these files are written by a python script from a template
#  before PyInstaller builds the exe, so as to inject date/other infos into it.
*.manifest
*.spec

# Installer logs
pip-log.txt
pip-delete-this-directory.txt

# Unit test / coverage reports
htmlcov/
.tox/
.nox/
.coverage
.coverage.*
.cache
nosetests.xml
coverage.xml

# Translations
*.mo
*.pot

# Django stuff:
*.log
local_settings.py

# Flask stuff:
instance/
.webassets-cache

# Scrapy stuff:
.scrapy

# Sphinx documentation
docs/_build/

# PyBuilder
target/

# Jupyter Notebook
.ipynb_checkpoints

# IPython
profile_default/
ipython_config.py

# pyenv
.python-version
.env/

# pipenv
.Pipfile
.Pipfile.lock

# Pylons
data.db

# Tornado
logs/

# Twisted web framework
twistd.log
twistd.pid

# Uppy
.node_modules/
.uppy/

# Yarn
node_modules/
)";

#endif