## simple docker container for waking up devices through [wolweb](https://github.com/sameerdhoot/wolweb) 

### quickstart
first remove the /w/ from wolweb webserver

create a directory for mikroBudzik and cd into it
curl example config and docker compose
```bash
curl -sL -o conf.toml https://raw.githubusercontent.com/tymoshh/mikroBudzik/main/conf.toml
curl -sL -o docker-compose.yml https://raw.githubusercontent.com/tymoshh/mikroBudzik/main/docker-compose.yml
```
tune the config to your needs
```bash
nano ./conf.toml
```
and run
```bash
docker compose up -d
```
and that is all

### credits
credits to toml++ because i used their toml parser
