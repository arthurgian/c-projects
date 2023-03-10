<a name="readme-top"></a>
<!-- PROJECT LOGO -->
<br />
<div align="center">
  <h3 align="center">Recursion Search</h3>

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
        <li><a href="#structure">Structure</a></li>
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

The goal of this exercise is to implement two data structures:

* `t_time`: A structure for working with hours, minutes, and seconds;
* `t_timetable`: An efficient symbol table for storing values associated with keys in the `time` format.

### Structure

| Return     | Operation | Description                                                                                 |
|------------|-----------|---------------------------------------------------------------------------------------------|
| `void`     | `put(t_time key, char * val)` | Inserts a key-value pair into the table (removes the element if the value is null) |
| `char *`   | `get(t_time key)` | Value associated with the key (null if the key is not present)                               |
| `void`     | `delete(t_time key)` | Removes the key and its associated value from the table                                      |
| `boolean`  | `contains(t_time key)` | Is there a value associated with the key?                                                     |
| `boolean`  | `is_empty()` | Is the table empty?                                                                          |
| `int`      | `size()` | Number of key-value pairs stored in the table                                                 |
| `t_time`   | `min()` | Smallest key stored in the table                                                             |
| `t_time`   | `max()` | Largest key stored in the table                                                              |
| `t_time`   | `floor(t_time key)` | Largest key less than or equal to the given key                                       |
| `t_time`   | `ceiling(t_time key)` | Smallest key greater than or equal to the given key                                  |
| `int`      | `rank(t_time key)` | Number of keys less than the given key                                                       |
| `t_time`   | `select(int k)` | Key of rank `k` in the table                                                                  |
| `void`     | `delete_min()` | Removes the smallest key                                                                      |
| `void`     | `delete_max()` | Removes the largest key                                                                       |
| `int`      | `size_range(t_time lo, t_time hi)` | Number of keys in the range [lo..hi]                                                |
| `t_time *` | `keys(t_time lo, t_time hi)` | Keys in the range [lo..hi] stored in the table                                              |


<!-- BUILT WITH -->
### Built With

This section should list the technologies used in this repository.

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

