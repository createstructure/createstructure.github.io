## How to create your own template

With createstructure service you can also use your own template.

A personal template to be usable needs:
- to be private
- to end with `-template`

How to create your own template:
- Create a private repository with the name endind with `-template` (for this step you can use the createstructure service)
- Costumize the repo with your own content
- Create a `.createstructure/change.json` like this:

```
{
  "This is the default template.": "soldescrsol",
  "createstructure/default-template": "solnamesol",
  "default-template": "solnamesol",
  "default": "solnamesol",
  "key": "value"
}
```
There are some special keys whict starts and ends with `sol`, the list is [this](https://github.com/createstructure/core-createstructure/blob/main/bin/local-libraries/repo.hpp#L375-L407)

- Push the repository
- Try the created template
