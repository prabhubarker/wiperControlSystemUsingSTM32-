{
	int i,b=0,j=0;  //Declaring and Initilizing Variables
	RCC_AHB1ENR |= (1<<3)|(1<<0); //Enabling the LED and the switch
	GPIOD_MODE = 0; //For Clear LED
	GPIOA_MODE = 0; //For Clear Switch
	GPIOA_IDR |= 1<<3;
	GPIOD_MODE |= (0<<25)|(1<<24);  //to assign LED 12 as output pin
	GPIOD_MODE |= (0<<27)|(1<<26);  //to assign LED 13 as output pin
	GPIOD_MODE |= (0<<29)|(1<<28);  //to assign LED 14 as output pin
	GPIOD_MODE |= (0<<31)|(1<<30);  //to assign LED 14 as output pin as per the Datasheet
	GPIOA_MODE |= (0<<1)|(0<<0);    //to assign Switch as input pin as per the Datasheet
	GPIOD_ODR = 0X00;
	while(1)
	{
					while((GPIOA_IDR & 0x01) == 1) // Switch Status On
					{
						b++; //Increment for Switch
					}
					if(b>30000)
				    {
					b=0;//RED Led should be in ON state
					GPIOD_ODR |= 1<<14;
					for(i=0;i<100000;i++);
					}
					else if(b>0 && b<30000)
					{
					j=1;
                    }
					else
					{

					}
						if(j==1)
						{

					    //By using Fast Frequency delay

				        for(j=0;j<5;j++) //For LED GREEN
						{
						GPIOD_ODR |= 1<<12;
						for(i=0;i<20000;i++);
						GPIOD_ODR &= ~(1<<12);
						for(i=0;i>=20000;i++);
						}
						for(j=0;j<5;j++)  //For LED ORANGE
						{
						GPIOD_ODR |= 1<<13;
						for(i=0;i<20000;i++);
						}
						for(j=0;j<5;j++)   //For LED BLUE
						{
						GPIOD_ODR |= 1<<15;
					
						GPIOD_ODR &= ~(1<<15);
						for(i=0;i>=20000;i++);
						}

						//Medium Speed Delay

						for(j=0;j<5;j++)  //For LED GREEN
						{
						GPIOD_ODR |= 1<<12;
						for(i=0;i<40000;i++);
						GPIOD_ODR &= ~(1<<12);
						for(i=0;i>=40000;i++);
						}
						for(j=0;j<5;j++)  //For LED ORANGE
						{
						GPIOD_ODR |= 1<<13;
						for(i=0;i<40000;i++);
						GPIOD_ODR &= ~(1<<13);
						for(i=0;i>=40000;i++);
						}
						for(j=0;j<5;j++)  //For LED BLUE
						{
						GPIOD_ODR |= 1<<15;
						for(i=0;i<40000;i++);
					    GPIOD_ODR &= ~(1<<15);
						for(i=0;i>=40000;i++);
						}
						//High Speed Delay

						for(j=0;j<5;j++)  //For LED GREEN
					    {
						GPIOD_ODR |= 1<<12;
						for(i=0;i<80000;i++);
						GPIOD_ODR &= ~(1<<12);
						for(i=0;i>=80000;i++);
						}
						for(j=0;j<5;j++)  //For LED ORANGE
						{
						GPIOD_ODR |= 1<<13;
						for(i=0;i<80000;i++);
						GPIOD_ODR &= ~(1<<13);
						for(i=0;i>=80000;i++);
						}
						for(j=0;j<5;j++)  //For LED BLUE
						{
						GPIOD_ODR |= 1<<15;
						for(i=0;i<80000;i++);
						GPIOD_ODR &= ~(1<<15);
						for(i=0;i>=80000;i++);
						}

						}


	}
	return 0;
}