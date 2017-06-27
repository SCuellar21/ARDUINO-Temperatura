char ask[1];
int val, valores[100];
float volts[100], tempts[100], volt, temp;

void setup()
{
  Serial.begin(9600);

  Serial.print("Ingresar los datos de temperatura? (s/n)");
  Serial.readBytes(ask,1);
  if(ask[0] == 's' || ask[0] == 'S'){
    for(int i=0; i<100; i++){
      valores[i] = analogRead(0);           //ENTRADA
      volts[i] = (valores[i]/1023.0)*5.0;   //VOLTAJE
      tempts[i] = volts[i]/10;               //TEMPERATURA
      delay(2000);
    }
    ask[0]='n';
  }

  for(int i=0; i<100; i++){
    Serial.print(valores[i]);
    Serial.print('\n');
    Serial.print(volts[i]);
    Serial.print('\n');
    Serial.print(tempts[i]);
    Serial.print('\n');
    Serial.print('\n');
  }
  
}

void loop()
{
  Serial.print("Iniciar a medir la temperatura? (s/n)");
  Serial.readBytes(ask,1);
  if(ask[0] == 's' || ask[0] == 'S'){
    val = analogRead(0);
    volt = (val/1023.0)*500.0; // (val/1023.0)*5000     5.0*100   (para aumentar los valores) == 500.0
    temp = volt/10;
    
    Serial.print("Temperatura = ");
    Serial.print(temp);
    Serial.print("°C");
    Serial.println('\n');
    delay(1000);
  }
  
}

