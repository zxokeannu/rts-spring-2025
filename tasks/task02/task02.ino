const int OFFSET = 2;
const int NUM_TRIALS = 102;
volatile unsigned long signalDeltas[NUM_TRIALS];
volatile int pulseIndex = 0;
volatile unsigned long lastTime = 0;

void setup() {
  Serial.begin(9600);
  pinMode(3, INPUT);
  attachInterrupt(digitalPinToInterrupt(3), InterruptHandler, HIGH);
}

void loop() {
  if (pulseIndex == NUM_TRIALS) {
    noInterrupts();
    
    unsigned long sum = 0;
    for (int i = OFFSET; i < NUM_TRIALS; i++) {
      sum += signalDeltas[i];
    }
    
    unsigned long avgPeriod = sum / (NUM_TRIALS);
    double stdDev = 0.0;
    
    for (int i = OFFSET; i < NUM_TRIALS; i++) {
      Serial.print("Period [");
      Serial.print(i);
      Serial.print("] : ");
      Serial.print(signalDeltas[i]);
      Serial.println(" us");
      
      stdDev += (avgPeriod - signalDeltas[i]) * (avgPeriod - signalDeltas[i]);
    }
    
    stdDev = sqrt(stdDev / NUM_TRIALS);
    
    Serial.print("Average Period: ");
    Serial.print(avgPeriod);
    Serial.print(" us, RMSD: ");
    Serial.print(stdDev);
    Serial.println(" us");
    Serial.println("");
    pulseIndex = 0;
    sum = 0;
    
    interrupts();
  }
}

void InterruptHandler() {
  unsigned long currentTime = micros();
  signalDeltas[pulseIndex] = currentTime - lastTime;
  lastTime = currentTime;
  pulseIndex++;
  }
