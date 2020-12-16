from setuptools import setup, find_packages
from requests import get

setup(
      name='createstructure',
      version='1.0.0',
      description='This is the magic bot by Castellani Davide. With this programm you can easly create a repository on GitHub with a basic template, personalized for your use.',
      long_description=get("https://raw.githubusercontent.com/CastellaniDavide/create_structure/master/docs/README.md").text,
      long_description_content_type="text/markdown",
      url='https://github.com/CastellaniDavide/create_structure',
      author='CastellaniDavide',
      author_email='help@castellanidavide.it',
      license='GNU',
      packages=find_packages(),
      python_requires=">=3.7",
      platforms="linux_distibution",
      install_requires=[
        "DateTime>=4.3",
        "PyGithub>=1.54",
        "requests>=2.24.0"
			],
      zip_safe=True
      )
