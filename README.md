# Level_US_GRO400_H21

## How to install the Python virtual environment

1. If not already installed, install Python 3 from the [Python website](https://www.python.org/downloads/).
2. Add the general directory of your Python installation and the sub-directory *Scripts* to your system's environment variables [Settings > System > About > System info > Advanced system settings > Environment variables > Path (under user variables)].
3. Open a command prompt and navigate to the project folder. *You can run `Python --version` and `pip --version` to make sure Python and pip are installed correctly*.
4. When in the project's directory you can create a new virtual environment using `python -m venv my_venv`.
5. Like for your system installation of Python, add your venv folder and it's *Scripts* sub-directory to your system's environment variables (like step 2).
6. To be able to use your different Python installation, you can create a .bat file with a different name i.g. python_myproject.bat.
7. Open this .bat file using a text editor and write `%~dp0python %*`.
8. In your command prompt you can now use python_myproject to refer to this specific installation.
9. To activate the venv, while in the project directory run `my_venv\Scripts\activate`.
10. Install the required module by running `pip install -r /path/to/requirements.txt`. *The requirements.txt file should be downloaded with the repository in the main project folder*.

### Add the venv to .gitignore

We do not want the venv to be pushed to Github in case of a push.

1. Open a git bash and navigate to your project directory linked with Github.
2. Run `echo 'my_venv' >> .gitignore` to add the venv to .gitignore. 

This way, the next you commit a change, the files in .gitignore will not be commited.