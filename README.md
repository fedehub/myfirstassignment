# Research Track I - first assignment

In this first assignment we were asked to control an holonomic robot within a 2d space with a simple 2d simulator, Stage. 
The simulator can be launched by executing the command:

```
rosrun stage_ros stageros $(rospack find assignment1)/world/exercise.world
```


# How the project is structured 


Once I have created a new ROS package, **two ROS nodes** have been developed. For writing the code I have chosen to adopt C++ programming language.

## The first node ##

The first node, [random_movement.cpp](https://github.com/fedehub/myfirstassignment/blob/main/src/random_movement.cpp), implement:

1. A ROS publisher
2. A ROS subscriber
3. A ROS client

## The second node  ##

The second node [random_service.cpp](https://github.com/fedehub/myfirstassignment/blob/main/src/random_service.cpp), implement a server whose aim is to compute 2 random numbers

## The rdm.srv file  ##

It is visible in the [srv](https://github.com/fedehub/myfirstassignment/blob/main/srv/) folder and it manages the request/reply of the custom service

## Documentation ##

The documentation of this project, obtained by means of **DoxyGen** is visible, within the [docs](https://github.com/fedehub/myfirstassignment/blob/main/docs) folder

# How to launch

1. Firstly, create a folder named _"myfirstassignment"_
2. Within the aforementioned folder, open the terminal and run
```
git clone https://github.com/fedehub/myfirstassignment/
```
3. Then, to launch the simulation enviroment, please run the comamnd
```
rosrun stage_ros stageros $(rospack find assignment1)/world/exercise.world
```
4. To launch the [firs node](https://github.com/fedehub/myfirstassignment/blob/main/src/random_movement.cpp), digit:

```
rosrun myfirstassignment rand_ser 

```
5. To launch the [second node](https://github.com/fedehub/myfirstassignment/blob/main/src/random_service.cpp), digit:

```
rosrun myfirstassignment rand_mov 

```

So far, the robot should appear in the simulation enviroment and once it reaches a target, it should move toward another direction, looking for the next one.