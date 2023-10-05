# ATmega32U4--2.1--ICR3-to-capture-rising-edge
使用Timer计数器，在信号上升沿的时候，读出ICR3里面存的数据  
### 电路图如下  
![image](https://github.com/wenxiwei00/ATmega32U4--2.1--ICR3-to-capture-rising-edge/assets/114196821/d8917169-3ac0-4475-bba5-3f7f3b790511)  
### 最快速度按开关，观察putty上ICR3的数值  
输出的数值是ICR3此刻存的数值。当我按下开关，信号会有个上升沿。这个上升沿对应的时间会被存到ICR3里面，ICR3就会更新数值。  

<img src="https://github.com/wenxiwei00/ATmega32U4--2.1--ICR3-to-capture-rising-edge/assets/114196821/b55fa9eb-1d88-48bf-a88e-adb422bb5a76" width="50">  

### 可以根据图上的数据算出我按开关的速度  
比如这里算的，我按键时间间隔是0.153s  
![image](https://github.com/wenxiwei00/ATmega32U4--2.1--ICR3-to-capture-rising-edge/assets/114196821/2ade2f1b-5013-42d4-8e04-e79288189868)



