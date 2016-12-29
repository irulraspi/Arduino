int LDR= A0;                    // membuat variabel LDR untuk pin A0
int LED_Merah = 13;            // membuat variabel LED untuk pin 11
int nilaiLDR= 0;            // variabel nilai awal untuk nilaiLDR
void setup(){
  pinMode(LED_Merah, OUTPUT);            // menentukan LED menjadi OUTPUT
 
  Serial.begin(9600);                 // komunikasi Arduino ke Komputer
}
void loop(){
  nilaiLDR= analogRead(LDR);                  // menyimpan nilai yang dibaca dari LDR ke variabel nilaiLDR
  Serial.print("NilaiLDR= ");                // menampilkan teks nilaiLDR=
  Serial.println(nilaiLDR);                 // menampilkan nilai dari nilaiLDR
  if(nilaiLDR > 700) {                     // jika nilai dari LDR kurang dari 700
    digitalWrite(LED_Merah, HIGH);        // lampu LED menyala
   
  }
  else  {                           // jika tidak
    digitalWrite(LED_Merah, LOW);         // lampu LED mati
   
  }
}


