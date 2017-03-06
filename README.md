# RT

[![N|Solid](http://www.42.fr/wp-content/themes/42/images/42_logo_black.svg)](https://github.com/alrickemilien)

Writed with dillinger.io

RT is a 3D realistic image maker using Raytracing technique powered in C.

  - Type some Markdown on the left
  - See HTML in the right
  - Magic

# New Features!

  - Import a HTML file and watch it magically convert to Markdown
  - Drag and drop images (requires your Dropbox account be linked)


You can also:
  - Import and save files from GitHub, Dropbox, Google Drive and One Drive
  - Drag and drop markdown and HTML files into Dillinger
  - Export documents as Markdown, HTML and PDF

Markdown is a lightweight markup language based on the formatting conventions that people naturally use in email.  As [John Gruber] writes on the [Markdown site][df1]

> The overriding design goal for Markdown's
> formatting syntax is to make it as readable
> as possible. The idea is that a
> Markdown-formatted document should be
> publishable as-is, as plain text, without
> looking like it's been marked up with tags
> or formatting instructions.

This text you see here is *actually* written in Markdown! To get a feel for Markdown's syntax, type some text into the left window and watch the results in the right.

### Tech

Dillinger uses a number of open source projects to work properly:

* [AngularJS] - HTML enhanced for web apps!
* [Ace Editor] - awesome web-based text editor
* [markdown-it] - Markdown parser done right. Fast and easy to extend.
* [Twitter Bootstrap] - great UI boilerplate for modern web apps
* [node.js] - evented I/O for the backend
* [Express] - fast node.js network app framework [@tjholowaychuk]
* [Gulp] - the streaming build system
* [Breakdance](http://breakdance.io) - HTML to Markdown converter
* [jQuery] - duh

And of course Dillinger itself is open source with a [public repository][dill]
 on GitHub.

### Installation

RT requires Node.js v4+ to run.

Install the dependencies and devDependencies and start the server. For MacOS environments : 

```sh
$ cd RT
$ git pull
$ ./RT
```

For LinuxOS environments :

```sh
$ npm install --production
$ npm run predeploy
$ NODE_ENV=production node app
```

### Objects

RT scenes gets differents objects :

| Objects | README |
| ------ | ------ |
| camera: | [plugins/dropbox/README.md] [PlDb] |
| light: | [plugins/github/README.md] [PlGh] |
| sphere: | [plugins/googledrive/README.md] [PlGd] |
| cone: | [plugins/onedrive/README.md] [PlOd] |
| cylinder: | [plugins/medium/README.md] [PlMe] |
| plan: | [plugins/googleanalytics/README.md] [PlGa] |
| csg: | [plugins/googleanalytics/README.md] [PlGa] |


### Camera

| Camera | Description |
| ------ | ------ |
| from: | [plugins/dropbox/README.md] [PlDb] |
| to: | [plugins/github/README.md] [PlGh] |

### Light

| Light | Description |
| ------ | ------ |
| position: | [plugins/dropbox/README.md] [PlDb] |
| intensity: | [plugins/github/README.md] [PlGh] |
| diffuse: | [plugins/dropbox/README.md] [PlDb] |
| specular: | [plugins/github/README.md] [PlGh] |

### Sphere

| Camera | Description |
| ------ | ------ |
| position: | [plugins/dropbox/README.md] [PlDb] |
| rayon: | [plugins/github/README.md] [PlGh] |
| color: | [plugins/dropbox/README.md] [PlDb] |
| diffuse: | [plugins/github/README.md] [PlGh] |
| specular: | [plugins/github/README.md] [PlGh] |
| rotation: | [plugins/dropbox/README.md] [PlDb] |
| translation: | [plugins/github/README.md] [PlGh] |
| brillance: | [plugins/dropbox/README.md] [PlDb] |
| transparent: | [plugins/github/README.md] [PlGh] |
| reflection: | [plugins/github/README.md] [PlGh] |
| refraction: | [plugins/github/README.md] [PlGh] |

### CSG

| CSG | Description |
| ------ | ------ |
| type: | [plugins/dropbox/README.md] [PlDb] |
| translation: | [plugins/github/README.md] [PlGh] |
| color: | [plugins/dropbox/README.md] [PlDb] |
| diffuse: | [plugins/github/README.md] [PlGh] |
| specular: | [plugins/github/README.md] [PlGh] |
| rotation: | [plugins/dropbox/README.md] [PlDb] |
| brillance: | [plugins/dropbox/README.md] [PlDb] |
| transparent: | [plugins/github/README.md] [PlGh] |
| reflection: | [plugins/github/README.md] [PlGh] |
| refraction: | [plugins/github/README.md] [PlGh] |

CSG objects are composed objects. Objects heritate the properties des sous objets. Un CSG est strictement composé de objets. Il est possible de faire des CSG de CSG, ex:


This file will produce a ...

### Cone

| Cone | Description |
| ------ | ------ |
| apex: | [plugins/dropbox/README.md] [PlDb] |
| axis: | [plugins/github/README.md] [PlGh] |
| angle: | [plugins/dropbox/README.md] [PlDb] |
| color: | [plugins/dropbox/README.md] [PlDb] |
| diffuse: | [plugins/github/README.md] [PlGh] |
| specular: | [plugins/github/README.md] [PlGh] |
| rotation: | [plugins/dropbox/README.md] [PlDb] |
| translation: | [plugins/github/README.md] [PlGh] |
| brillance: | [plugins/dropbox/README.md] [PlDb] |
| transparent: | [plugins/github/README.md] [PlGh] |
| reflection: | [plugins/github/README.md] [PlGh] |
| refraction: | [plugins/github/README.md] [PlGh] |

### Cylinder

blabla

| Cone | Description |
| ------ | ------ |
| apex: | [plugins/dropbox/README.md] [PlDb] |
| rayon: | [plugins/dropbox/README.md] [PlDb] |
| axis: | [plugins/github/README.md] [PlGh] |
| color: | [plugins/dropbox/README.md] [PlDb] |
| diffuse: | [plugins/github/README.md] [PlGh] |
| specular: | [plugins/github/README.md] [PlGh] |
| rotation: | [plugins/dropbox/README.md] [PlDb] |
| translation: | [plugins/github/README.md] [PlGh] |
| brillance: | [plugins/dropbox/README.md] [PlDb] |
| transparent: | [plugins/github/README.md] [PlGh] |
| reflection: | [plugins/github/README.md] [PlGh] |
| refraction: | [plugins/github/README.md] [PlGh] |

### Exemple

```json
csg:
{
    type: ()
    color:()

    csg:
    {
        sphere:
        {
            position: ()
            color: ()
            rayon: ()
        }
        cylinder:
        {
            apex: ()
            axis: ()
            color: ()
            rayon: ()
        }
    }
    cylinder:
    {
        apex: ()
        axis: ()
         color: ()
         rayon: ()
    }
}
```
### Docker
Dillinger is very easy to install and deploy in a Docker container.

By default, the Docker will expose port 80, so change this within the Dockerfile if necessary. When ready, simply use the Dockerfile to build the image.

```sh
cd dillinger
docker build -t joemccann/dillinger:${package.json.version}
```
This will create the dillinger image and pull in the necessary dependencies. Be sure to swap out `${package.json.version}` with the actual version of Dillinger.

Once done, run the Docker image and map the port to whatever you wish on your host. In this example, we simply map port 8000 of the host to port 80 of the Docker (or whatever port was exposed in the Dockerfile):

```sh
docker run -d -p 8000:8080 --restart="always" <youruser>/dillinger:${package.json.version}
```

Verify the deployment by navigating to your server address in your preferred browser.

```sh
127.0.0.1:8000
```


### Todos

 - Add Night Mode

Contributors
----

salibert, wbellhac, aemilien


**Free Software, Hell Yeah!**

[//]: # (These are reference links used in the body of this note and get stripped out when the markdown processor does its job. There is no need to format nicely because it shouldn't be seen. Thanks SO - http://stackoverflow.com/questions/4823468/store-comments-in-markdown-syntax)


   [dill]: <https://github.com/joemccann/dillinger>
   [git-repo-url]: <https://github.com/joemccann/dillinger.git>
   [john gruber]: <http://daringfireball.net>
   [df1]: <http://daringfireball.net/projects/markdown/>
   [markdown-it]: <https://github.com/markdown-it/markdown-it>
   [Ace Editor]: <http://ace.ajax.org>
   [node.js]: <http://nodejs.org>
   [Twitter Bootstrap]: <http://twitter.github.com/bootstrap/>
   [jQuery]: <http://jquery.com>
   [@tjholowaychuk]: <http://twitter.com/tjholowaychuk>
   [express]: <http://expressjs.com>
   [AngularJS]: <http://angularjs.org>
   [Gulp]: <http://gulpjs.com>

   [PlDb]: <https://github.com/joemccann/dillinger/tree/master/plugins/dropbox/README.md>
   [PlGh]: <https://github.com/joemccann/dillinger/tree/master/plugins/github/README.md>
   [PlGd]: <https://github.com/joemccann/dillinger/tree/master/plugins/googledrive/README.md>
   [PlOd]: <https://github.com/joemccann/dillinger/tree/master/plugins/onedrive/README.md>
   [PlMe]: <https://github.com/joemccann/dillinger/tree/master/plugins/medium/README.md>
   [PlGa]: <https://github.com/RahulHP/dillinger/blob/master/plugins/googleanalytics/README.md>
