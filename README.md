# Joystick Brick Breaker

This is a little project that let you play classical game Brick Breaker with a small joystick.

## What you need?
* [Arduino borad](https://www.arduino.cc/en/Main/Products){:target="_blank"} (uno, mega and due, etc...)
* [JoyStick](http://wiki.dfrobot.com.cn/index.php?title=(SKU:DFR0061)JoyStick摇杆模块){:target="_blank"}
* [USB Cable](https://www.adafruit.com/products/62){:target="_blank"} and [Dupont Lines](http://www.amazon.com/Qooltek-40pcs-Dupont-Female-Connector/dp/B0116IZ0UO){:target="_blank"}

## How it works?

First see how connect all the devices:

![][id]
[id]: https://github.com/fangbq/JoystickBrickBreaker/blob/master/img/JoyStick%20Brick%20Breaker%20Structure.png?raw=true

Details between arduino board and joystick:
![](https://github.com/fangbq/JoystickBrickBreaker/blob/master/img/Arduino-JoyStick.png?raw=true)

When the ①(player) control the ②(joystick), such as pushing and pulling, then the *control data* caught by arduino with a arduino program running on the ③(arduino board). This arduino program also pass the *control data* to ④(labtop) through usb cable.

The rest job is using the *control data* play the game.

In the following processing program, we can got *control data* from serial:

```c
BrickBreaker_GameView.pde

// open port/serial
myPort = new Serial(this, portName, 9600); // must got the right portName !!!
// read data from joystick
void readData() {
     // update position info
    if(myPort.available() > 2) {
    	int val = myPort.read();
    	// ...
    }
}
```

Then you can use the data to contol the board move to left and right by the serial protocol designed by yourself.

![](https://github.com/fangbq/JoystickBrickBreaker/blob/master/img/GameView.png?raw=true)


## How to deploy?
1. Load the arduino program `BrickBreaker_DataReader.ino` in the directory *src/BrickBreaker_DataReader* to your arduino board. ([Arduino Beginner](https://www.arduino.cc/en/Guide/HomePage)){:target="_blank"}
2. Open `BrickBreaker_GameView.pde` with [Processing IDE](https://processing.org/download/?processing), then click run!

	Notice:
	
	######1.	If you don't want to download processing ide, you can just run the executable file that suit to your os in directory *exe*.
	######2. You may get errors or see nothing when you run the processing program `BrickBreaker_GameView.pde` or when you execute the exetuable files provided. The possible solution is to change the value of `portNumber` in line 61, then this processing program can get access to the right serial that communicates with your arduino board.

## Enjoy the game!
// video here

## Extending with Buletooth
// todo

## Reference
* [Processing](https://processing.org){:target="_blank"} - it's an powerful programming language that helps you design interesting application fastly, such as Brick Breaker game.
* [OpenProcessing](http://www.openprocessing.org){:target="_blank"} - OpenProcessing is a website to share Processing sketches. I got the src of the game Brick Breaker from [Brick Breaker](http://www.openprocessing.org/sketch/134612).


