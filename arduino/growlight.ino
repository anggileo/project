#include <Wire.h>
const int DS1307 = 0x68; // Address of DS1307 see data sheets
const char* days[] =
{"Minggu", "Senin", "Selasa", "Rabu", "Kamis", "Jum'at", "Sabtu"};
const char* months[] =
{"Januari", "Februari", "Maret", "April", "Mei", "Juni", "Juli", "Augustus","September", "Oktober", "November", "Desember"};
 
// Initializes all values: 
byte second = 0;
byte minute = 0;
byte hour = 0;
byte weekday = 0;
byte monthday = 0;
byte month = 0;
byte year = 0;
byte init1=0;
byte varw=0;
//byte init2=0;
#include <LiquidCrystal.h>
int contrast=100;
int pincontrast = 8;
int pinlcdlight =7;
LiquidCrystal lcd(12, 11, 6,5, 4, 3);
char ch;
int varl=0;
int stvarl=0;
int growlight=2;
int fan=13;
int vccdht=10;
byte deg= B11011111; //karakter derajat
byte longtime = 0; //lama waktu nyala, 0=default
#include <DHT.h>
#define DHTTYPE DHT22
#define DHTPIN 9
DHT dht(DHTPIN, DHTTYPE);

//setup
void setup() {
pinMode(vccdht,OUTPUT);
digitalWrite(vccdht,HIGH);
ch = 0;
varl=0;
Wire.begin();
Serial.begin(9600);
printTime();
lcd.begin(16,2);
dht.begin();
analogWrite(pincontrast,contrast); 
analogWrite(pinlcdlight,28000);

if(ch==0){Serial.println("mode otomatis berjalan");}
if(ch==1){Serial.println("mode manual berjalan");}
Serial.println("0=otomatis  1=manual " );

pinMode (growlight , OUTPUT );
pinMode (fan, OUTPUT );
}

// loop
void loop() {
//sense();
VarL();
stVarL();
dhtDisplay();
Timedisplay();
mode();
lcdlamapenyinaran();
}
///fungsi
byte decToBcd(byte val) {
  return ((val/10*16) + (val%10));
}
byte bcdToDec(byte val) {
  return ((val/16*10) + (val%16));
}

void dhtDisplay(){
float h = dht.readHumidity();
float t = dht.readTemperature();
    lcd.setCursor(1,0);
    lcd.print(h);
    lcd.print("% ");
    lcd.print(t);
    lcd.write(deg);
    lcd.print("C");
}

void Timedisplay(){

readTime();
lcd.setCursor(4, 1);
digit(hour);
lcd.print(':' );
digit(minute);
lcd.print(':' );
digit(second);
}

void stVarL(){

if(stvarl==2){
digitalWrite (growlight, HIGH );
digitalWrite (fan, HIGH );
}
if(stvarl==3){
digitalWrite (growlight, LOW );
digitalWrite (fan, LOW );
}

}

void mode(){
if (varl==0){
lcd.setCursor(1,1);
lcd.print('a' );
}
if (varl==1){
lcd.setCursor (1, 1);
lcd.print ('m' );
}
}
void VarL(){
if (varl==0){otomatis();

}
if (varl==1){serialEvent();}
}

//void manual(){
//}
void otomatis(){
readTime();

switch(longtime){
  case 1:
  if ((hour>=6) *(minute>=0) && (hour<=6)*(minute <=59)){
    stvarl=2;
    }
    else 
    {
    stvarl=3;
    }
    break;
  case 2:
  if ((hour>=6) *(minute>=0) && (hour<=7)*(minute <=59)){
    stvarl=2;
    }
    else 
    {
    stvarl=3;
    }
    break;
  case 3:
  if ((hour>=6) *(minute>=0) && (hour<=8)*(minute <=59)){
    stvarl=2;
    }
    else 
    {
    stvarl=3;
    }
    break;
  case 4:
  if ((hour>=6) *(minute>=0) && (hour<=9)*(minute <=59)){
    stvarl=2;
    }
    else 
    {
    stvarl=3;
    }
    break;
  case 5:
  if ((hour>=6) *(minute>=0) && (hour<=10)*(minute <=59)){
    stvarl=2;
    }
    else 
    {
    stvarl=3;
    }
    break;
  case 6:
  if ((hour>=6) *(minute>=0) && (hour<=11)*(minute <=59)){
    stvarl=2;
    }
    else 
    {
    stvarl=3;
    }
    break;
  case 7:
  if ((hour>=6) *(minute>=0) && (hour<=12)*(minute <=59)){
    stvarl=2;
    }
    else 
    {
    stvarl=3;
    }
    break;
  case 8:
  if ((hour>=6) *(minute>=0) && (hour<=13)*(minute <=59)){
    stvarl=2;
    }
    else 
    {
    stvarl=3;
    }
    break;
  case 9:
  if ((hour>=6) *(minute>=0) && (hour<=14)*(minute <=59)){
    stvarl=2;
    }
    else 
    {
    stvarl=3;
    }
    break;
  case 10:
  if ((hour>=6) *(minute>=0) && (hour<=15)*(minute <=59)){
    stvarl=2;
    }
    else 
    {
    stvarl=3;
    }
    break;
  case 11:
  if ((hour>=6) *(minute>=0) && (hour<=16)*(minute <=59)){
    stvarl=2;
    }
    else 
    {
    stvarl=3;
    }
    break;
  case 12:
  if ((hour>=6) *(minute>=0) && (hour<=17)*(minute <=59)){
    stvarl=2;
    }
    else 
    {
    stvarl=3;
    }
    break;
  case 13:
  if ((hour>=6) *(minute>=0) && (hour<=18)*(minute <=59)){
    stvarl=2;
    }
    else 
    {
    stvarl=3;
    }
    break;
  case 14:
  if ((hour>=6) *(minute>=0) && (hour<=19)*(minute <=59)){
    stvarl=2;
    }
    else 
    {
    stvarl=3;
    }
    break;
  case 15:
  if ((hour>=6) *(minute>=0) && (hour<=20)*(minute <=59)){
    stvarl=2;
    }
    else 
    {
    stvarl=3;
    }
    break;
  case 16:
  if ((hour>=6) *(minute>=0) && (hour<=21)*(minute <=59)){
    stvarl=2;
    }
    else 
    {
    stvarl=3;
    }
    break;
  case 17:
  if ((hour>=6) *(minute>=0) && (hour<=22)*(minute <=59)){
    stvarl=2;
    }
    else 
    {
    stvarl=3;
    }
    break;
  case 18:
  if ((hour>=6) *(minute>=0) && (hour<=23)*(minute <=59)){
    stvarl=2;
    }
    else 
    {
    stvarl=3;
    }
    break;
  case 19:
  if ((hour>=1) *(minute>=0) && (hour<=5)*(minute <=59)){
    stvarl=3;
    }
    else 
    {
    stvarl=2;
    }
    break;
  case 20:
  if ((hour>=2) *(minute>=0) && (hour<=5)*(minute <=59)){
    stvarl=3;
    }
    else 
    {
    stvarl=2;
    }
    break;
  case 21:
  if ((hour>=3) *(minute>=0) && (hour<=5)*(minute <=59)){
    stvarl=3;
    }
    else 
    {
    stvarl=2;
    }
    break;
  case 22:
  if ((hour>=4) *(minute>=0) && (hour<=5)*(minute <=59)){
    stvarl=3;
    }
    else 
    {
    stvarl=2;
    }
    break;
  case 23:
  if ((hour>=5) *(minute>=0) && (hour<=5)*(minute <=59)){
    stvarl=3;
    }
    else 
    {
    stvarl=2;
    }
    break;
  default:
  if ((hour>=6) *(minute>=0) && (hour<=17)*(minute <=59)){
    stvarl=2;
    }
    else 
    {
    stvarl=3;
    }
  break;
}
if(longtime>23){
  Serial.println("tidak diperbolehkan, hanya 1-23");
  longtime=0;        
}
 //nyala pukul 6 mati pukul 18
        
}

void digit(int number){
if (number>=0 && number<10){
    lcd.print('0' );
    }
    lcd.print(number);
}

// This set of codes is allows input of data
void setTime() {
Serial.println("initializing");

init1=readByte();

//Serial.print(init1);

//Serial.println (" init 1 done");
Serial.print("tahun saat ini, 00-99.");
  year = readByte();
  Serial.println(year);
  Serial.print("bulan saat ini, 1-12. ");
  month = readByte();
  Serial.println(months[month-1]);
  Serial.print("tanggal saat ini, 1-31. - ");
  monthday = readByte();
  Serial.println(monthday);
  Serial.println("hari saat ini, 1-7.");
  Serial.print("1 Min | 2 Sen | 3 Sel | 4 Rab | 5 Kam | 6 Jum | 7 Sab - ");
  weekday = readByte();
  Serial.println(days[weekday-1]);
init1=weekday;
//Serial.print(init2);
//Serial.print("init 2 done");
  Serial.print("jam saat ini, 0-23. - ");
  hour = readByte();
  Serial.println(hour);
  Serial.print("menit saat ini, 0-59. - ");
  minute = readByte();
  Serial.println(minute);
  second = 0;
  Serial.println("data sudah dimasukkan.");
   Serial.println("transmisi data kembali berjalan");
  // The following codes transmits the data to the RTC
  Wire.beginTransmission(DS1307);
  Wire.write(byte(0));
  Wire.write(decToBcd(second));
  Wire.write(decToBcd(minute));
  Wire.write(decToBcd(hour));
  Wire.write(decToBcd(weekday));
  Wire.write(decToBcd(monthday));
  Wire.write(decToBcd(month));
  Wire.write(decToBcd(year));
  Wire.write(byte(0));
  Wire.endTransmission();
  // Ends transmission of data
}

byte readByte() {
  while (!Serial.available()) delay(10);
  byte reading = 0;
  byte incomingByte = Serial.read();
  while (incomingByte != '\n') {
    if (incomingByte >= '0' && incomingByte <= '9')
      reading = reading * 10 + (incomingByte - '0');
    else;
    incomingByte = Serial.read();
  }
  Serial.flush();
  return reading;
}

void printTime() {
  char buffer[3];
  const char* AMPM = 0;
  readTime();
  Serial.print(days[weekday-1]);
  Serial.print(" ");
Serial.print(monthday);
Serial.print(" ");
  Serial.print(months[month-1]);
  Serial.print(", 20");
  Serial.print(year);
  Serial.print(" ");
  if (hour > 12) {
    hour -= 12;
    AMPM = " PM";
  }
  else AMPM = " AM";
  Serial.print(hour);
  Serial.print(":");
  sprintf(buffer, "%02d", minute);
  Serial.print(buffer);
  Serial.print(":");
  Serial.print(second);
  Serial.println(AMPM);
}

void readTime() {
  Wire.beginTransmission(DS1307);
  Wire.write(byte(0));
  Wire.endTransmission();
  Wire.requestFrom(DS1307, 7);
  second = bcdToDec(Wire.read());
  minute = bcdToDec(Wire.read());
  hour = bcdToDec(Wire.read());
  weekday = bcdToDec(Wire.read());
  monthday = bcdToDec(Wire.read());
  month = bcdToDec(Wire.read());
  year = bcdToDec(Wire.read());
}
void longt(){
  init1=readByte();
Serial.println("lama penyinaran saat ini= ");
Serial.print(longtime);
Serial.print(" jam");
  Serial.println("masukkan lama penyinaran:");
  Serial.println("");
    longtime=readByte();
    if (longtime>23){
      Serial.print("tidak boleh, hanya 1-23");
      longtime=0;
    }else if (longtime==0){
      Serial.print(" default");
    }else{
    Serial.print(" baik,");
   Serial.print (longtime); 
  Serial.print(" jam");
    }
}
void serialEvent()
{
       if (Serial.available())
  {
    ch= Serial.read();
 

    if (ch=='0' )
    {
     //auto mode  
    //varl=0;
    Serial.println ("mode otomatis berjalan");
    varl=0;
    Serial.println(varl);
    }
    if(ch=='1' )
    //varl=1;
    {
     //manual mode
    Serial.println ("mode manual berjalan");
    Serial.println("2=nyala 3=mati a=atur waktu b=baca waktu l=atur lama penyinaran p=monitor sensor dht");
    varl=1;
    Serial.println(varl);
    }
    if ((ch=='p')&&(varl==1)){
    //sense();
    Serial.print("cek sukses");
sense();
Serial.println("done");
    }

    if((ch=='2' )&&(varl==1))
    {
    //stvarl=2;
    Serial.println ("nyala");
    stvarl=2;
    Serial.println(stvarl);
    }
    if((ch=='3' )&&(varl==1))
    {
    //stvarl=3;
    Serial.println ("mati");    
    stvarl=3;
    Serial.println(stvarl);
    }

    if((ch=='a' )&&(varl==1))
    {
    //stvarl=3;
    Serial.println ("atur waktu");
    Serial.println ("perhatian! ");
    Serial.println ("transmisi data akan berhenti");
    Serial.println("5=reset z=tahun x=bulan c=tanggal v=hari h=jam n=menit m=detik");
    varw=1;
    Serial.println(varw);
    }
    if ((ch=='5')&&(varw==1)&&(varl==1)){
      setTime();
      printTime();
    }else
    if((ch=='z')&&(varw==1)&&(varl==1)){
      tahun();
      printTime();
    }else
    if ((ch=='x')&&(varw==1)&&(varl==1)){
      bulan();
      printTime();
    }else
    if ((ch=='c')&&(varw==1)&&(varl==1)){
      tanggal();
      printTime();
    }else
    if ((ch=='v')&&(varw==1)&&(varl==1)){
      hari();
      printTime();
    }else
    if ((ch=='h')&&(varw==1)&&(varl==1)){
      jam();
      printTime();
    }else
    if ((ch=='n')&&(varw==1)&&(varl==1)){
      menit();
      printTime();
    }else
    if ((ch=='m')&&(varw==1)&&(varl==1)){
      detik();
      printTime();
    }
    if((ch=='b' )&&(varl==1))
    {
    //stvarl=3;
    Serial.println ("baca waktu");    
    printTime();
    }
    if((ch=='l')&&(varl==1))
    {
      longt();
      ch=1;
    }
    

    if((ch=='2' )&&(varl==0)){
    Serial.println("ubah ke mode manual! ");
    }
    if((ch=='3' )&&(varl==0)){
    Serial.println("ubah ke mode manual! ");
    }
    
    if((ch=='a' )&&(varl==0)){
    Serial.println("ubah ke mode manual! ");
    }

    if((ch=='b' )&&(varl==0)){
    Serial.println("ubah ke mode manual! ");
    }
    if((ch=='l' )&&(varl==0)){
    Serial.println("ubah ke mode manual! ");
    }
    if((ch=='5' )&&(varl==0)){
    Serial.println("ubah ke mode manual! ");
    }
    if((ch=='z' )&&(varl==0)){
    Serial.println("ubah ke mode manual! ");
    }
    if((ch=='x' )&&(varl==0)){
    Serial.println("ubah ke mode manual! ");
    }
    if((ch=='c' )&&(varl==0)){
    Serial.println("ubah ke mode manual! ");
    }
    if((ch=='v' )&&(varl==0)){
    Serial.println("ubah ke mode manual! ");
    }
    if((ch=='h' )&&(varl==0)){
    Serial.println("ubah ke mode manual! ");
    }
    if((ch=='n' )&&(varl==0)){
    Serial.println("ubah ke mode manual! ");
    }
    if((ch=='m' )&&(varl==0)){
    Serial.println("ubah ke mode manual! ");
    }
    if((ch=='p' )&&(varl==0)){
    Serial.println("ubah ke mode manual! ");
    }
    if((ch=='5' )&&(varw==0)&&(varl==1)){
    Serial.println("atur waktu dulu! ");
    }
    if((ch=='z' )&&(varw==0)&&(varl==1)){
    Serial.println("atur waktu dulu! ");
    }
    if((ch=='x' )&&(varw==0)&&(varl==1)){
    Serial.println("atur waktu dulu! ");
    }
    if((ch=='c' )&&(varw==0)&&(varl==1)){
    Serial.println("atur waktu dulu! ");
    }
    if((ch=='v' )&&(varw==0)&&(varl==1)){
    Serial.println("atur waktu dulu! ");
    }
    if((ch=='h' )&&(varw==0)&&(varl==1)){
    Serial.println("atur waktu dulu! ");
    }
    if((ch=='n' )&&(varw==0)&&(varl==1)){
    Serial.println("atur waktu dulu! ");
    }
    if((ch=='m' )&&(varw==0)&&(varl==1)){
    Serial.println("atur waktu dulu! ");
    }
  
}
}
void lcdlamapenyinaran(){
  if(longtime<=9){
  lcd.setCursor(14,1);
  lcd.print(longtime);
  }
  if (longtime>9){
    lcd.setCursor(13,1);
    lcd.print(longtime);
  }
}
void tahun(){
    init1=readByte();
   Serial.print("tahun saat ini, 0-99. - ");
  year = readByte();
  Serial.println(year);
  Serial.println("data sudah dimasukkan.");
   Serial.println("transmisi data kembali berjalan");
  // The following codes transmits the data to the RTC
  Wire.beginTransmission(DS1307);
  Wire.write(byte(0));
  Wire.write(decToBcd(second));
  Wire.write(decToBcd(minute));
  Wire.write(decToBcd(hour));
  Wire.write(decToBcd(weekday));
  Wire.write(decToBcd(monthday));
  Wire.write(decToBcd(month));
  Wire.write(decToBcd(year));
  Wire.write(byte(0));
  Wire.endTransmission();
  // Ends transmission of data
}
void bulan(){
    init1=readByte();
   Serial.print("bulan saat ini, 1-12. - ");
  month = readByte();
  Serial.println(month);
  Serial.println("data sudah dimasukkan.");
   Serial.println("transmisi data kembali berjalan");
  // The following codes transmits the data to the RTC
  Wire.beginTransmission(DS1307);
  Wire.write(byte(0));
  Wire.write(decToBcd(second));
  Wire.write(decToBcd(minute));
  Wire.write(decToBcd(hour));
  Wire.write(decToBcd(weekday));
  Wire.write(decToBcd(monthday));
  Wire.write(decToBcd(month));
  Wire.write(decToBcd(year));
  Wire.write(byte(0));
  Wire.endTransmission();
  // Ends transmission of data
}
void tanggal(){
    init1=readByte();
   Serial.print("tanggal saat ini saat ini, 0-31. - ");
  monthday = readByte();
  Serial.println(monthday);
  Serial.println("data sudah dimasukkan.");
   Serial.println("transmisi data kembali berjalan");
  // The following codes transmits the data to the RTC
  Wire.beginTransmission(DS1307);
  Wire.write(byte(0));
  Wire.write(decToBcd(second));
  Wire.write(decToBcd(minute));
  Wire.write(decToBcd(hour));
  Wire.write(decToBcd(weekday));
  Wire.write(decToBcd(monthday));
  Wire.write(decToBcd(month));
  Wire.write(decToBcd(year));
  Wire.write(byte(0));
  Wire.endTransmission();
  // Ends transmission of data
}
void hari(){
    init1=readByte();
   Serial.print("hari saat ini, minggu 1-sabtu 7 - ");
  weekday = readByte();
  Serial.println(weekday);
  Serial.println("data sudah dimasukkan.");
   Serial.println("transmisi data kembali berjalan");
  // The following codes transmits the data to the RTC
  Wire.beginTransmission(DS1307);
  Wire.write(byte(0));
  Wire.write(decToBcd(second));
  Wire.write(decToBcd(minute));
  Wire.write(decToBcd(hour));
  Wire.write(decToBcd(weekday));
  Wire.write(decToBcd(monthday));
  Wire.write(decToBcd(month));
  Wire.write(decToBcd(year));
  Wire.write(byte(0));
  Wire.endTransmission();
  // Ends transmission of data
}
void jam(){
    init1=readByte();
   Serial.print("jam saat ini, 0-23. - ");
  hour = readByte();
  Serial.println(hour);
  Serial.println("data sudah dimasukkan.");
   Serial.println("transmisi data kembali berjalan");
  // The following codes transmits the data to the RTC
  Wire.beginTransmission(DS1307);
  Wire.write(byte(0));
  Wire.write(decToBcd(second));
  Wire.write(decToBcd(minute));
  Wire.write(decToBcd(hour));
  Wire.write(decToBcd(weekday));
  Wire.write(decToBcd(monthday));
  Wire.write(decToBcd(month));
  Wire.write(decToBcd(year));
  Wire.write(byte(0));
  Wire.endTransmission();
  // Ends transmission of data  
}
void menit(){
  init1=readByte();
   Serial.print("menit saat ini, 0-59. - ");
  minute = readByte();
  Serial.println(minute);
  Serial.println("data sudah dimasukkan.");
   Serial.println("transmisi data kembali berjalan");
  // The following codes transmits the data to the RTC
  Wire.beginTransmission(DS1307);
  Wire.write(byte(0));
  Wire.write(decToBcd(second));
  Wire.write(decToBcd(minute));
  Wire.write(decToBcd(hour));
  Wire.write(decToBcd(weekday));
  Wire.write(decToBcd(monthday));
  Wire.write(decToBcd(month));
  Wire.write(decToBcd(year));
  Wire.write(byte(0));
  Wire.endTransmission();
  // Ends transmission of data
}
void detik(){
    init1=readByte();
   Serial.print("detik saat ini, 0-59. - ");
  second = readByte();
  Serial.println(second);
  Serial.println("data sudah dimasukkan.");
   Serial.println("transmisi data kembali berjalan");
  // The following codes transmits the data to the RTC
  Wire.beginTransmission(DS1307);
  Wire.write(byte(0));
  Wire.write(decToBcd(second));
  Wire.write(decToBcd(minute));
  Wire.write(decToBcd(hour));
  Wire.write(decToBcd(weekday));
  Wire.write(decToBcd(monthday));
  Wire.write(decToBcd(month));
  Wire.write(decToBcd(year));
  Wire.write(byte(0));
  Wire.endTransmission();
  // Ends transmission of data
}
void sense(){

float h=dht.readHumidity();
float t=dht.readTemperature();
Serial.println ();
Serial.print(h);
Serial.print(" %   ");
Serial.print(t);
Serial.println(" °C");
}
