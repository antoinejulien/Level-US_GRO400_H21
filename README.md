# Level_US_GRO400_H21
## First prototype
![alt text](https://github.com/antoinejulien/Level-US_GRO400_H21/blob/python-gui/Images/Prototype1.jpg=720x480)

## How to install the Python virtual environment (on Windows)

1. If not already installed, install Python 3 from the [Python website](https://www.python.org/downloads/).
2. Add the root directory of your Python installation (i.g. Python38) and the sub-directory *Scripts* to your system's environment variables [Settings > System > About > System info > Advanced system settings > Environment variables > Path (under user variables)].
3. Open a command prompt and navigate to the project folder. *You can run `python --version` and `pip --version` to make sure Python and pip are installed correctly*.
4. When in the project's directory you can create a new virtual environment using `python -m venv name_venv`.
5. Like for your system installation of Python, add your venv folder and it's *Scripts* sub-directory to your system's environment variables (like step 2).
6. To be able to use your different Python installation, you can create a .bat file with a different name i.g. python_myproject.bat.
7. Open this .bat file using a text editor and write `%~dp0python %*`.
8. In your command prompt you can now use python_myproject to refer to this specific installation.
9. To activate the venv, while in the project directory run `my_venv\Scripts\activate`.
10. Install the required module by running `pip install -r /path/to/requirements_win.txt`. *The requirements_win.txt file should be downloaded with the repository in the main project folder*.

## How to install the Python environment (on Linux)

1. If not already installed, download and install the latest Python 3 version from the [Python website](https://www.python.org/downloads/source/) following [this guide](https://www.dummies.com/programming/python/how-to-install-python-on-a-linux-system/).
2. Install pip using `sudo apt install python3-pip`
3. Install venv using `sudo appt install python3-venv`
4. Open a command prompt and navigate to the project folder. *You can run `python3 --version` and `pip --version` to make sure Python and pip are installed correctly on Linux python*.
6. When in the project's directory you can create a new virtual environment using `python3 -m venv name_venv`.
7. Go to the newly environment folder using `cd name_venv\bin` and run `source activate` to activate the venv.
8. Run `pip install -r /path/to/requirements_linux.txt` to install the required modules. *The requirements_linux.txt file should be downloaded with the repository in the main project folder*.


## How to install the Python environment (on MacOS)

1. If not already installed, install Python 3 from the [Python website](https://www.python.org/downloads/mac-osx/).
2. 

### Add the venv to .gitignore

We do not want the venv to be pushed to Github in case of a push.

1. Open a git bash and navigate to your project directory linked with Github.
2. Run `echo 'my_venv' >> .gitignore` to add the venv to .gitignore. 

This way, the next you commit a change, the files in .gitignore will not be commited.
