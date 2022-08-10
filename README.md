# Research Track I - first assignment

In this first assignment we were asked to control an holonomic robot within a 2d space with a simple 2d simulator, Stage.
The simulator can be launched by executing the command:

```
rosrun stage_ros stageros $(rospack find myfirstassignment)/world/exercise.world
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

## Rqt-graph (ROS tool)

By running the following command:

```
rosrun rqt_graph rqt_graph

```
it is possible to show a dynamic graph, depicting what is going on within the System.

![rqt_graph](https://github.com/fedehub/myfirstassignment/blob/main/rqt_graph/rosgraph.png "Rqt_graph - first assignment")



## Documentation

The documentation of this project, obtained by means of **DoxyGen** is visible, within the [docs](https://github.com/fedehub/myfirstassignment/blob/main/docs) folder

## Meta

Federico Civetta– s4194543 – fedeunivers@gmail.com

Distributed under none licence

https://github.com/fedehub

# How to launch

1. Firstly, create a folder named _"myfirstassignment"_
2. Within the aforementioned folder, open the terminal and run
```
git clone https://github.com/fedehub/myfirstassignment/
```
3. Secondly, start the master in background, by running: 

```
roscore &

```
3. Then, to launch the simulation environment, please open a new shell tab and run the command
```
rosrun stage_ros stageros $(rospack find myfirstassignment)/world/exercise.world
```
4. To launch the [firs node](https://github.com/fedehub/myfirstassignment/blob/main/src/random_movement.cpp), open another shell tab and digit:

```
rosrun myfirstassignment rand_ser

```
5. To launch the [second node](https://github.com/fedehub/myfirstassignment/blob/main/src/random_service.cpp), open another shell tab and  digit:

```
rosrun myfirstassignment rand_mov

```

So far, the robot should appear in the simulation environment and once it reaches a target, it should move toward another direction, looking for the next one.



# Release History

* 0.1.0
 * The first proper release

* 0.0.1
 * Work in progress

## Contributing

1. Fork it (https://github.com/fedehub/myfirstassignment/fork)
2. Create your feature branch (git checkout -b feature/fooBar)
3. Commit your changes (git commit -am 'Add some fooBar')
4. Push to the branch (git push origin feature/fooBar)
5. Create a new Pull Request
