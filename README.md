# space-invaders-unlam
Space Invaders videogame written from scratch, as an educational porpose project.<br>
National University of La Matanza, Buenos Aires, Argentina

#### Intro
A dockerized version is available to show how the game works (through a web browser)
without struggling with operating system or package versions.
As it is a network game, you could expose the container hostname, and invite your friends to play.

#### Pre-requisites
- [Docker](https://docs.docker.com/get-docker/)
- [Docker-compose](https://docs.docker.com/compose/install/)

#### Build and run service
`docker-compose up -d --build`

#### Access container via browser and play game
[localhost:6080](http://127.0.0.1:6080/)

##### Start game server
- Start button (bottom-left) -> Accessories -> LXTerminal
- `cd /usr/src/spaceinvaders/Servidor`
- `make`
- `./server`

##### Run client
- Open new terminal (or new tab on current)
- `cd /usr/src/spaceinvaders/Cliente`
- `make`
- `./cliente`

##### Game rules
- You need at least 2 clients to start a game
- Each player faces the other only once.
- Then they will be on hold until a new player joins the server
- Press keys `a` and `l` to move your ship left and right
- Press key `g` to fire
- If you hit the red ship, you get extra points

#### Access container via cli
`docker-compose exec spaceinv bash`
You cannot play the game from here. Just to put your hands inside the container