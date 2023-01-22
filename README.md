# aabrahm
Is a wish-list web app written in C++ using 
Crow and Google test for the backend and AngularJS 
for the frontend.

## Getting started (using Docker)
- Clone the repository using
`git clone https://github.com/StefanoPetrilli/aabrham.git`
- Exec `setup.sh` to create the docker container
- Compile and run using the `aabrham-container` container. 
Remember to expose the port `18080` to access Crow. It is 
possible to do so using the parameter `-p 127.0.0.1:18080:18080` when running 
the container.
- Access the app connecting to `127.0.0.1:18080`