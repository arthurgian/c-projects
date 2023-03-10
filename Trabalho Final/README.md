<a name="readme-top"></a>
<!-- PROJECT LOGO -->
<br />
<div align="center">
  <h3 align="center">Indexer</h3>

  <p align="center">
    <br />
    <a href="https://github.com/arthurgian/c-projects"><strong>Explore other C projects! »</strong></a>
    <br />
  </p>
</div>



<!-- TABLE OF CONTENTS -->
<details>
  <summary>Table of Contents</summary>
  <ol>
    <li>
      <a href="#about-the-project">About The Project</a>
      <ul>
        <li><a href="#built-with">Built With</a></li>
      </ul>
    </li>
    <li>
      <a href="#getting-started">Getting Started</a>
      <ul>
        <li><a href="#prerequisites">Prerequisites</a></li>
      </ul>
    </li>
  </ol>
</details>



<!-- ABOUT THE PROJECT -->
## About The Project

The project consists of creating a program capable of indexing words from one or more text documents.

* NAME
indexer - index words from text documents

* SYNOPSIS
indexer --freq N FILE
indexer --freq-word WORD FILE
indexer --search TERM FILE [FILE ...]

* DESCRIPTION
The indexer program counts the occurrence of words in text documents.
Based on this count, it allows searching for the number of occurrences of a
specific word in a document or selecting relevant documents for a given
search term.
The indexer program transforms all letters to lowercase and ignores
characters such as numbers and punctuations.
When executed with the --freq option, the indexer program will display
the number of occurrences of the N most frequent words in the document
passed as a parameter, in descending order of occurrences.
When executed with the --freq-word option, the indexer program displays
the count of a specific word in the document passed as a parameter.
Finally, when executed with the --search option, the indexer program
presents a list of the most relevant documents for a given search term.
To do so, the program uses the TF-IDF (Term Frequency-Inverse Document
Frequency) calculation.

* OPTIONS
--freq N FILE
Displays the number of occurrences of the N words that appear the most in
FILE, in descending order of occurrence.
--freq-word WORD FILE
Displays the number of occurrences of WORD in FILE.
--search TERM FILE [FILE ...]
Displays a list of the most relevant FILES found by searching for TERM.
The list is presented in descending order of relevance.
TERM may contain more than

<!-- BUILT WITH -->
### Built With

This section should list the technologies used in this project.

* [![C][C.io]][C-url]


<!-- GETTING STARTED -->
## Getting Started

This is the instructions to set up the project locally.
To get a local copy up and running the project, follow these steps.

### Prerequisites

* GCC Compiler

<!-- MARKDOWN LINKS & IMAGES -->
<!-- https://www.markdownguide.org/basic-syntax/#reference-style-links -->
[Next.js]: https://img.shields.io/badge/next.js-000000?style=for-the-badge&logo=nextdotjs&logoColor=white
[Next-url]: https://nextjs.org/
[React.js]: https://img.shields.io/badge/React-20232A?style=for-the-badge&logo=react&logoColor=61DAFB
[React-url]: https://reactjs.org/
[Vue.js]: https://img.shields.io/badge/Vue.js-35495E?style=for-the-badge&logo=vuedotjs&logoColor=4FC08D
[Vue-url]: https://vuejs.org/
[Angular.io]: https://img.shields.io/badge/Angular-DD0031?style=for-the-badge&logo=angular&logoColor=white
[Angular-url]: https://angular.io/
[Svelte.dev]: https://img.shields.io/badge/Svelte-4A4A55?style=for-the-badge&logo=svelte&logoColor=FF3E00
[Svelte-url]: https://svelte.dev/
[Laravel.com]: https://img.shields.io/badge/Laravel-FF2D20?style=for-the-badge&logo=laravel&logoColor=white
[Laravel-url]: https://laravel.com
[Bootstrap.com]: https://img.shields.io/badge/Bootstrap-563D7C?style=for-the-badge&logo=bootstrap&logoColor=white
[Bootstrap-url]: https://getbootstrap.com
[JQuery.com]: https://img.shields.io/badge/jQuery-0769AD?style=for-the-badge&logo=jquery&logoColor=white
[JQuery-url]: https://jquery.com
[CSS3.io]: https://img.shields.io/badge/CSS3-1572B6?style=for-the-badge&logo=css3&logoColor=white
[CSS3-url]: https://www.css3.com/
[HTML5.io]: https://img.shields.io/badge/HTML5-E34F26?style=for-the-badge&logo=html5&logoColor=white
[HTML5-url]: https://html5.org/
[C.io]: https://img.shields.io/badge/C-00599C?style=for-the-badge&logo=c&logoColor=white
[C-url]: https://devdocs.io/c/

