# Inception 🐳

"Inception" is a project that involves configuring a mini containerized web app using Docker. This project helps to get familiar with creating and managing Docker containers, as well as orchestrating services via `docker compose`.

## Objectives

- Configure a simple web application using multiple Docker containers.
- Use `docker compose` to orchestrate the different services.
- Set up services such as Nginx, WordPress, and MariaDB with custom images.
- Isolate the services using Docker networks and volumes.

## Project Structure

The project is organized around several services defined in the `docker-compose.yml` file:

- **Nginx**: Acts as a web server to handle HTTP and HTTPS requests.
- **WordPress**: Provides a content management interface to create and manage websites.
- **MariaDB**: Relational database to store WordPress data.

Bonus services:
- **Redis Cache**: In-memory data structure store to cache WordPress data.
- **vsFTPd**: A secure and fast FTP server for transferring files.
- **Adminer**: A full-featured database management tool written in PHP.
- **Prometheus** with **Grafana**: Monitoring and alerting toolkit with a powerful visualization dashboard.
- **Static Website**: A simple static website served by Nginx.

## Usage

This project aims to work on a local machine with Docker and Make installed. To ensure full compatibility, the `DOMAIN` local variable inside the [`.env`](srcs/example.env) file needs to be linked to localhost (`127.0.0.1`).   

To launch the project, simply paste the following command at the root of this project:
```bash
make
```

The services should be accesible through the specified domain name.


## Conclusion

The Inception project is an excellent introduction to containerization with Docker and service orchestration with `docker-compose`. By configuring a simple web application, this project teaches the basics of container and service management.
