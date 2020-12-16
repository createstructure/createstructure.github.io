from setuptools import setup, find_packages
from requests import get

setup(
      name='createstructure',
      version=get("https://api.github.com/repos/CastellaniDavide/create_structure/tags").json()[0]['name'].replace("v", ""), # Lastest release
      description=get("https://api.github.com/repos/CastellaniDavide/create_structure").json()['description'],
      long_description=get("https://raw.githubusercontent.com/CastellaniDavide/create_structure/master/docs/README.md").text,
      long_description_content_type="text/markdown",
      url=get("https://api.github.com/repos/CastellaniDavide/create_structure").json()['html_url'],
      author=get("https://api.github.com/repos/CastellaniDavide/create_structure").json()['owner']['login'],
      author_email=get(f"https://api.github.com/users/{get('https://api.github.com/repos/CastellaniDavide/create_structure').json()['owner']['login']}").json()['email'],
      license='GNU',
      packages=find_packages(),
      python_requires=">=3.7",
      platforms="linux_distibution",
      install_requires=[i for i in get("https://raw.githubusercontent.com/CastellaniDavide/create_structure/master/requirements/requirements.txt").text.split("\n") if not "#" in i and i != ''],
      zip_safe=True
      )
