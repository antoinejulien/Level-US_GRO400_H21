//Code de test de positions moteurs 

#include <DynamixelWorkbench.h>

#if defined(__OPENCM904__)
  #define DEVICE_NAME "3" //Dynamixel on Serial3(USART3)  <-OpenCM 485EXP
#elif defined(__OPENCR__)
  #define DEVICE_NAME ""
#endif   

#define BAUDRATE  57600
#define DXL_ID_1    215
#define DXL_ID_2    209
#define DXL_ID_3    202


int X = 0;
int Speed = 50;

DynamixelWorkbench dxl_wb;

void setup() 
{
  Serial.begin(57600);
  // while(!Serial); // Wait for Opening Serial Monitor

  const char *log;
  bool result = false;

  uint8_t dxl_id_1 = DXL_ID_1;
  uint8_t dxl_id_2 = DXL_ID_2;
  uint8_t dxl_id_3 = DXL_ID_3;
  uint16_t model_number = 0;

  result = dxl_wb.init(DEVICE_NAME, BAUDRATE, &log);
  if (result == false)
  {
    Serial.println(log);
    Serial.println("Failed to init");
  }
  else
  {
    Serial.print("Succeeded to init : ");
    Serial.println(BAUDRATE);  
  }
  result = dxl_wb.ping(dxl_id_1, &model_number, &log);
  result = dxl_wb.ping(dxl_id_2, &model_number, &log);
  result = dxl_wb.ping(dxl_id_3, &model_number, &log);
  if (result == false)
  {
    Serial.println(log);
    Serial.println("Failed to ping");
  }
  else
  {
    Serial.println("Succeeded to ping");
    Serial.print("id : ");
    Serial.print(dxl_id_1);
    Serial.print(" model_number : ");
    Serial.println(model_number);
  }
  result = dxl_wb.jointMode(dxl_id_1, Speed, 0, &log);
  result = dxl_wb.jointMode(dxl_id_2, Speed, 0, &log);
  result = dxl_wb.jointMode(dxl_id_3, Speed, 0, &log);
  if (result == false)
  {
    Serial.println(log);
    Serial.println("Failed to change joint mode");
  }
  else
  {
    Serial.println("Succeed to change joint mode");
    Serial.println("Dynamixel is moving...");

    for (int count = 0; count < 1; count++)
    {
      float Angle = X*2*PI/360;
      
      dxl_wb.goalPosition(dxl_id_1, (float)Angle);//(int32_t)1023
      dxl_wb.goalPosition(dxl_id_2, (float)Angle);//(int32_t)1023
      dxl_wb.goalPosition(dxl_id_3, (float)Angle);//(int32_t)1023
      delay(5000);
    }
  }
}

void loop() 
{
    
    int position;
    int Pos_;
 
    uint8_t dxl_id_1 = DXL_ID_1;
    uint8_t dxl_id_2 = DXL_ID_2;
    uint8_t dxl_id_3 = DXL_ID_3;

    if (Serial.available() > 0) 
    {
      position = Serial.readString().toInt();
    }
    
    if(position == 3)
    {
      Pos_ = -90;
      float Angle = Pos_*2*PI/360;
      
      dxl_wb.goalPosition(dxl_id_1, (float)Angle);
      dxl_wb.goalPosition(dxl_id_2, (float)Angle);
      dxl_wb.goalPosition(dxl_id_3, (float)Angle);

      Serial.println("DONE\n");
      position = 0;
    }

    if(position == 2)
    {   
      Pos_ = -45;
      float Angle = Pos_*2*PI/360;
      
      dxl_wb.goalPosition(dxl_id_1, (float)Angle);
      dxl_wb.goalPosition(dxl_id_2, (float)Angle);
      dxl_wb.goalPosition(dxl_id_3, (float)Angle);

      Serial.println("DONE\n");
      position = 0;
    }

    if(position == 1)
    {
      Pos_ = 0;
      float Angle = Pos_*2*PI/360;
      
      dxl_wb.goalPosition(dxl_id_1, (float)Angle);
      dxl_wb.goalPosition(dxl_id_2, (float)Angle);
      dxl_wb.goalPosition(dxl_id_3, (float)Angle);

      Serial.println("DONE\n");
      position = 0;
    }
}
