//7-Segment Display
//Brandon Ackerman, RBT173
//https://youtu.be/rRPRKjDkRSg

//create variables for pins a-g on our display.
int a = 7;
int b = 8;
int c = 9;
int d = 10;
int e = 11;
int f = 12;
int g = 13;

//setup code
void setup()
{
    Serial.begin(9600); //starts the serial monitor at baud rate 9600.
for (int i = 7; i <= 13; i++) //configure "i" to inherit the values of pins 7 through 13.
{
    pinMode(i,OUTPUT); //set "i" as outputs.
}

for (int i = 2; i <= 5; i++) //configure "i" to inherit the values of pins 2 through 5.
{
    pinMode(i,INPUT_PULLUP); //set "i" as a pullup resistor input.
}
}

//main code loop
void loop()
{ //create read variables for our switches on pins 2-5.
    int val0 = digitalRead(2);
    int val1 = digitalRead(3);
    int val2 = digitalRead(4);
    int val3 = digitalRead(5);

//read pins 2,3,4,5 as binary inputs, but in reverse logic.
//if in binary 0 config (0000), read zero.
    if(val0 == 1 && val1 == 1 && val2 == 1 && val3 == 1)
    {
        clear(); //clear the display.
        number0(); //display number 0.
    }
//if in binary 1 config (0001, inv. 1110), read one.
    else if (val0 == 0 && val1 == 1 && val2 == 1 && val3 == 1)
    {
        clear(); //clear the display.
        number1(); //display number 1.
    }
//if in binary 2 config (0011, inv. 1101), read two.
    else if (val0 == 1 && val1 ==0 && val2 == 1 && val3 == 1)
    {
        clear(); //clear the display.
        number2(); //display number 2.
    }
//if in binary 3 config (0011, inv. 1100), read three.
    else if (val0 == 0 && val1 ==0 && val2 == 1 && val3 == 1)
    {
        clear(); //clear the display.
        number3(); //display number 3.
    }
//if in binary 4 config (0100, inv. 1011), read four.
    else if (val0 == 1 && val1 ==1 && val2 == 0 && val3 == 1)
    {
        clear(); //clear the display.
        number4(); //display number 4.
    }
    //if in binary 5 config (0101, inv. 1010), read five.
    else if (val0 == 0 && val1 ==1 && val2 == 0 && val3 == 1)
    {
        clear(); //clear the display.
        number5(); //display number 5.
    }
//if in binary 6 config (0110, inv. 1001), read six.
    else if (val0 == 1 && val1 ==0 && val2 ==0  && val3 ==1 )
    {
        clear(); //clear the display.
        number6(); //display number 6.
    }
//if in binary 7 config (0111, inv 1000), read seven.
    else if (val0 == 0 && val1 == 0 && val2 == 0 && val3 == 1)
    {
        clear(); //clear the display.
        number7(); //display number 7.
    }
//if in binary 8 config (1000), inv. 0111), read eight.
    else if (val0 == 1 && val1 ==1 && val2 == 1 && val3 == 0)
    {
        clear(); //clear the display.
        number8(); //display number 8.
    }
//if in binary 9 config (1001, inv. 0110), read nine.
    else if (val0 == 0 && val1 ==1 && val2 == 1 &a& val3 == 0)
    {
            clear(); //clear the display.
        number9(); //display number 9.
    }
    else
    { 
      	clear(); //clear the display.
      //print the line "Not in range" to the serial console.
        Serial.println("Not in range");
    }
    delay(1000); //wait one second.
}

void clear()
{
digitalWrite(a, LOW);
digitalWrite(b, LOW);
digitalWrite(c, LOW);
digitalWrite(d, LOW);
digitalWrite(e, LOW);
digitalWrite(f, LOW);
digitalWrite(g, LOW);
Serial.println("clear");
}

void number0()
{
    digitalWrite(a, HIGH);
    digitalWrite(b, HIGH);
    digitalWrite(c, HIGH);
    digitalWrite(d, HIGH);
    digitalWrite(e, HIGH);
    digitalWrite(f, HIGH);
    digitalWrite(g, LOW);
    Serial.println("0");
}

void number1()
{
   // digitalWrite(a, LOW);
    digitalWrite(b, HIGH);
    digitalWrite(c, HIGH);
   // digitalWrite(d, LOW);
   // digitalWrite(e, LOW);
    //digitalWrite(f, LOW);
    //digitalWrite(g, LOW);
    Serial.println("1");
}
void number2()
{
    digitalWrite(a, HIGH);
    digitalWrite(b, HIGH);
    //digitalWrite(c, LOW);
    digitalWrite(d, HIGH);
    digitalWrite(e, HIGH);
    //digitalWrite(f, LOW);
    digitalWrite(g, HIGH);

    Serial.println("2");
}
void number3()
{
    digitalWrite(a, HIGH);
    digitalWrite(b, HIGH);
    digitalWrite(c, HIGH);
    digitalWrite(d, HIGH);
    //digitalWrite(e, LOW);
    //digitalWrite(f, LOW);
    digitalWrite(g, HIGH);
    Serial.println("3");
}
void number4()
{
    //digitalWrite(a, LOW);
    digitalWrite(b, HIGH);
    digitalWrite(c, HIGH);
    //digitalWrite(d, LOW);
    //digitalWrite(e, LOW);
    digitalWrite(f, HIGH);
    digitalWrite(g, HIGH);

    Serial.println("4");
}
void number5()
{
    digitalWrite(a, HIGH);
    //digitalWrite(b, LOW);
    digitalWrite(c, HIGH);
    digitalWrite(d, HIGH);
   // digitalWrite(e, LOW);
    digitalWrite(f, HIGH);
    digitalWrite(g, HIGH);

    Serial.println("5");
}
void number6()
{
    digitalWrite(a, HIGH);
    //digitalWrite(b, LOW);
    digitalWrite(c, HIGH);
    digitalWrite(d, HIGH);
    digitalWrite(e, HIGH);
    digitalWrite(f, HIGH);
    digitalWrite(g, HIGH);

    Serial.println("6");
}
void number7()
{
    digitalWrite(a, HIGH);
    digitalWrite(b, HIGH);
    digitalWrite(c, HIGH);
   // digitalWrite(d, LOW);
    //digitalWrite(e, LOW);
    //digitalWrite(f, LOW);
   // digitalWrite(g, LOW);
    Serial.println("7");
}
void number8()
{
    digitalWrite(a, HIGH);
    digitalWrite(b, HIGH);
    digitalWrite(c, HIGH);
    digitalWrite(d, HIGH);
    digitalWrite(e, HIGH);
    digitalWrite(f, HIGH);
    digitalWrite(g, HIGH);
    Serial.println("8");
}
void number9()
{
    digitalWrite(a, HIGH);
    digitalWrite(b, HIGH);
    digitalWrite(c, HIGH);
    digitalWrite(d, HIGH);
    //digitalWrite(e, LOW);
    digitalWrite(f, HIGH);
    digitalWrite(g, HIGH);
    Serial.println("9");
}




