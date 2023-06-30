
int led_pin = A0;
int pinA = D12;
int pinB = D11;
int pinC = D10;
int pinD = D9;
//const byte interruptPin = 10 ; //버튼스위치 input을 interrupt로 활용
//volatile byte state = LOW ; // 전역변수들이 ISR내부에 동기화가 되기 위해 해결

char result_type = 0;
char number = 0;
int pinE = D8;
int pinF = D7;
int pinG = D6;
int pinDP = D1;

int PORT1 = D5 ;
int PORT2 = D4 ;
int PORT3 = D3 ;
int PORT4 = D2 ;

int seg_ctl[4][4] = {{1,1,1,0}, {1,1,0,1}, {1,0,1,1}, {0,1,1,1}};
int seg_data[16][8] = {
  {1,0,0,1,1,1,0,0}, //C
  {1,1,1,1,1,1,0,0}, //O
  {1,0,1,0,1,0,0,0}, //M
  {1,0,0,1,1,1,1,0}, //E
  {1,0,1,1,0,1,1,0}, //S
  {0,0,0,1,1,1,1,0}, //T
  {1,1,1,1,1,1,0,0}, //O
  {1,1,0,0,1,1,1,0}, //P
  {1,1,1,0,1,1,0,0}, //N
  {1,1,1,1,1,1,0,0}, //O
  {1,1,1,0,1,1,0,0}, //N
  {1,0,0,1,1,1,1,0}, //E
  {1,1,1,0,1,1,1,0}, //A
  {0,1,0,1,0,1,0,0}, //W
  {1,1,1,0,1,1,1,0}, //A
  {0,1,1,1,0,1,1,0}, //Y
} ;



void setup() {
  // put your setup code here, to run once:
  Serial1.begin(9600) ;
  //attachInterrupt(digitalPinToInterrupt(interruptPin),ISR, RISING);
  pinMode(pinA, OUTPUT); //D pin들을 output으로 설정
  pinMode(pinB, OUTPUT);
  pinMode(pinC, OUTPUT);
  pinMode(pinD, OUTPUT);
  pinMode(pinE, OUTPUT);
  pinMode(pinF, OUTPUT);
  pinMode(pinG, OUTPUT);
  pinMode(pinDP, OUTPUT);

  pinMode(PORT1, OUTPUT);
  pinMode(PORT2, OUTPUT);
  pinMode(PORT3, OUTPUT);
  pinMode(PORT4, OUTPUT);
  pinMode(led_pin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial1.available()){
    result_type = Serial1.read() ;
    }
  if(result_type == '0') //come
  {  
    number = '0';
    digitalWrite(led_pin, LOW);
  }   
  else if(result_type == '1') //stop
  {     
    number = '1';
    digitalWrite(led_pin, LOW);
  }  
  else if(result_type == '2') //none
  {
    number = '2'; //none
    digitalWrite(led_pin, HIGH);
  }
  else //away
  {
    number = '3';
    digitalWrite(led_pin, LOW);
  }
  display_number(0, number);
  display_number(1, number);
  display_number(2, number);
  display_number(3, number);
  
}

void display_number(int digit, char number) // FND자리, 나타낼 문자
{
    if( number == '0'){
    digitalWrite(PORT1, seg_ctl[digit][0]);
    digitalWrite(PORT2, seg_ctl[digit][1]);
    digitalWrite(PORT3, seg_ctl[digit][2]);
    digitalWrite(PORT4, seg_ctl[digit][3]);

    digitalWrite(pinA, seg_data[digit][0]);
    digitalWrite(pinB, seg_data[digit][1]);
    digitalWrite(pinC, seg_data[digit][2]);
    digitalWrite(pinD, seg_data[digit][3]);
    digitalWrite(pinE, seg_data[digit][4]);
    digitalWrite(pinF, seg_data[digit][5]);
    digitalWrite(pinG, seg_data[digit][6]);
    digitalWrite(pinDP, seg_data[digit][7]);
    delay(2.5) ;
    }
    if( number == '1'){
    digitalWrite(PORT1, seg_ctl[digit][0]);
    digitalWrite(PORT2, seg_ctl[digit][1]);
    digitalWrite(PORT3, seg_ctl[digit][2]);
    digitalWrite(PORT4, seg_ctl[digit][3]);

    digitalWrite(pinA, seg_data[digit+4][0]);
    digitalWrite(pinB, seg_data[digit+4][1]);
    digitalWrite(pinC, seg_data[digit+4][2]);
    digitalWrite(pinD, seg_data[digit+4][3]);
    digitalWrite(pinE, seg_data[digit+4][4]);
    digitalWrite(pinF, seg_data[digit+4][5]);
    digitalWrite(pinG, seg_data[digit+4][6]);
    digitalWrite(pinDP, seg_data[digit+4][7]);
    delay(2.5) ;
    }
    if( number == '2'){
    digitalWrite(PORT1, seg_ctl[digit][0]);
    digitalWrite(PORT2, seg_ctl[digit][1]);
    digitalWrite(PORT3, seg_ctl[digit][2]);
    digitalWrite(PORT4, seg_ctl[digit][3]);

    digitalWrite(pinA, seg_data[digit+8][0]);
    digitalWrite(pinB, seg_data[digit+8][1]);
    digitalWrite(pinC, seg_data[digit+8][2]);
    digitalWrite(pinD, seg_data[digit+8][3]);
    digitalWrite(pinE, seg_data[digit+8][4]);
    digitalWrite(pinF, seg_data[digit+8][5]);
    digitalWrite(pinG, seg_data[digit+8][6]);
    digitalWrite(pinDP, seg_data[digit+8][7]);
    delay(2.5) ;
    }
    if( number == '3'){
    digitalWrite(PORT1, seg_ctl[digit][0]);
    digitalWrite(PORT2, seg_ctl[digit][1]);
    digitalWrite(PORT3, seg_ctl[digit][2]);
    digitalWrite(PORT4, seg_ctl[digit][3]);

    digitalWrite(pinA, seg_data[digit+12][0]);
    digitalWrite(pinB, seg_data[digit+12][1]);
    digitalWrite(pinC, seg_data[digit+12][2]);
    digitalWrite(pinD, seg_data[digit+12][3]);
    digitalWrite(pinE, seg_data[digit+12][4]);
    digitalWrite(pinF, seg_data[digit+12][5]);
    digitalWrite(pinG, seg_data[digit+12][6]);
    digitalWrite(pinDP, seg_data[digit+12][7]);
    delay(2.5) ;
    }
  }