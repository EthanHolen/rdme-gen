<!--
*** Thanks for checking out this README Template. If you have a suggestion that would
*** make this better, please fork the rdme-gen and create a pull request or simply open
*** an issue with the tag "enhancement".
*** Thanks again! Now go create something AMAZING! :D
-->





<!-- PROJECT SHIELDS -->
<!--
*** I'm using markdown "reference style" links for readability.
*** Reference links are enclosed in brackets [ ] instead of parentheses ( ).
*** See the bottom of this document for the declaration of the reference variables
*** for contributors-url, forks-url, etc. This is an optional, concise syntax you may use.
*** https://www.markdownguide.org/basic-syntax/#reference-style-links
-->
[![Contributors][contributors-shield]][contributors-url]
[![Forks][forks-shield]][forks-url]
[![Stargazers][stars-shield]][stars-url]
[![Issues][issues-shield]][issues-url]
[![MIT License][license-shield]][license-url]
[![LinkedIn][linkedin-shield]][linkedin-url]



<!-- PROJECT LOGO -->
<br />
<p align="center">
  <a href="https://github.com/EthanHolen/rdme-gen">
    <img src="rdme-images/markdown.PNG" alt="Logo" width="100" height="80">
  </a>

  <h2 align="center">README Generator</h2>

  <p align="center">
    This is a project to create a homebrew tap which can generate a fillable README in your current directory. 
    <br />
    <a href="https://github.com/EthanHolen/rdme-gen"><strong>Explore the docs »</strong></a>
    <br />
    <br />
    <a href="https://github.com/EthanHolen/rdme-gen">View Demo</a>
    ·
    <a href="https://github.com/EthanHolen/rdme-gen/issues">Report Bug</a>
    ·
    <a href="https://github.com/EthanHolen/rdme-gen/issues">Request Feature</a>
  </p>
</p>



<!-- TABLE OF CONTENTS -->
## Table of Contents

- [Table of Contents](#table-of-contents)
- [About The Project](#about-the-project)
  - [Built With](#built-with)
- [Getting Started](#getting-started)
  - [Prerequisites](#prerequisites)
  - [Installation](#installation)
- [Usage](#usage)
- [Roadmap](#roadmap)
- [License](#license)
- [Contact](#contact)
- [Acknowledgements](#acknowledgements)



<!-- ABOUT THE PROJECT -->
## About The Project


### Built With

* [Python](https://www.python.org/)
* [Ruby](https://www.ruby-lang.org/en/)



<!-- GETTING STARTED -->
## Getting Started

To install this on your personal machine follow these simple steps.

### Prerequisites

* [Homebrew](https://brew.sh/)

1. Go to the [Homebrew](https://brew.sh/) page.
2. Follow the instructions there to install the latest version of homebrew on to your mac.

### Installation
 
1. After installing homebrew paste this into your terminal
```sh
brew tap EthanHolen/taps
```
2. Then install the software by pasting
```sh
brew install rdme-gen
```



<!-- USAGE EXAMPLES -->
## Usage

The first time you run `rdme-gen` you will be prompted to clone the default templates into your home directory, the file will be called `~/.readmeTemplates/`

> Feel free to edit the README files in this directory as they will be the ones copied when running the rdme-gen comand (be careful though, changing the file structure or names of files will cause the program to fail)

![Product Name Screen Shot][product-screenshot2]
 


When `rdme-gen` is run with no flags the default README template is copied into the current directory. 

![Product Name Screen Shot][product-screenshot]

Currently `rdme-gen` has two flags `-f`, which will prompt you with questions and then do a search and replace inside the README to easily get you started on your docs and  `-img`, which will populate in a `rdme-images` folder to store images for the README.

![Product Name Screen Shot][product-screenshot3]


<!-- ROADMAP -->
## Roadmap

See the [open issues](https://github.com/EthanHolen/rdme-gen/issues) for a list of proposed features (and known issues).

* Customize the README a bit to be better for autofill.
* Add many more autofillable fields.
* Create more templates and tags.
* Long Term, rewrite program in C++ or Rust for easier Homebrew integration.



<!-- CONTRIBUTING
## Contributing

Contributions are what make the open source community such an amazing place to be learn, inspire, and create. Any contributions you make are **greatly appreciated**.

1. Fork the Project
2. Create your Feature Branch (`git checkout -b feature/AmazingFeature`)
3. Commit your Changes (`git commit -m 'Add some AmazingFeature'`)
4. Push to the Branch (`git push origin feature/AmazingFeature`)
5. Open a Pull Request -->



<!-- LICENSE -->
## License

Distributed under the MIT License. See `LICENSE` for more information.



<!-- CONTACT -->
## Contact

Name - [@HolenEthan](https://twitter.com/HolenEthan) - ethanholen@gmail.com

Project Link: [https://github.com/EthanHolen/rdme-gen](https://github.com/EthanHolen/rdme-gen)



<!-- ACKNOWLEDGEMENTS -->
## Acknowledgements

* Thanks to [othneildrew](https://github.com/othneildrew) for his awesome [readme](https://github.com/othneildrew/Best-README-Template) template.
* Thanks to [jakevossen5](https://github.com/jakevossen5) for letting me steal some of his code when I had no idea what I was doing.






<!-- MARKDOWN LINKS & IMAGES -->
<!-- https://www.markdownguide.org/basic-syntax/#reference-style-links -->
[contributors-shield]: https://img.shields.io/github/contributors/othneildrew/Best-README-Template.svg?style=flat-square
[contributors-url]: https://github.com/EthanHolen/rdme-gen/graphs/contributors

[forks-shield]: https://img.shields.io/github/forks/EthanHolen/rdme-gen.svg?style=flat-square
[forks-url]: https://github.com/EthanHolen/rdme-gen/network/members

[stars-shield]: https://img.shields.io/github/stars/EthanHolen/rdme-gen.svg?style=flat-square
[stars-url]: https://github.com/EthanHolen/rdme-gen/stargazers

[issues-shield]: https://img.shields.io/github/issues/EthanHolen/rdme-gen.svg?style=flat-square
[issues-url]: https://github.com/EthanHolen/rdme-gen/issues

[license-shield]: https://img.shields.io/github/license/EthanHolen/rdme-gen.svg?style=flat-square
[license-url]: https://github.com/EthanHolen/rdme-gen/blob/master/LICENSE

[linkedin-shield]: https://img.shields.io/badge/-LinkedIn-black.svg?style=flat-square&logo=linkedin&colorB=555
[linkedin-url]: https://www.linkedin.com/in/ethan-holen-563856174

[product-screenshot]: rdme-images/usage1.png
[product-screenshot2]: rdme-images/usage0.png
[product-screenshot3]: rdme-images/usage2.png

