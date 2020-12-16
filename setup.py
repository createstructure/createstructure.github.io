from setuptools import setup, find_packages

setup(
      name='createstructure',
      version='5.6',
      description='This is the magic bot by Castellani Davide. With this programm you can easly create a repository on GitHub with a basic template, personalized for your use.',
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
