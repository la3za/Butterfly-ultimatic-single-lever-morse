void paddle()
{

	if (keyer == 0)   // Direct: output = input   
	  { 
	 	  l_out = !(0x01 & l_in); r_out= !(0x01 & r_in); // Boolean inverse
	  }
	  else  	  
	  {

	 /* 
	 	Direct implementation of table 3 in "K Schmidt (W9CF)
     	"An ultimatic adapter for iambic keyers"
     	http://fermi.la.asu.edu/w9cf/articles/ultimatic/ultimatic.html
	 
	 	with the addition of the Single-paddle emulation mode
     */ 
		if (state==0)
		{	 
	 		if ((l_in==0) & (r_in==0)) 
			// two paddles closed, right first
			{
	    		state = 0;

				if (keyer==1) 		// Ultimatic
				{
					l_out = 1; r_out = 0; // change to left
				}
				else if (keyer==2) 	// Single-paddle emulation
				{ 
					l_out = 0; r_out = 1; // keep right
				}
				
		    }
			else if ((l_in==0) & (r_in==1))
			{
				state = 1; l_out = 1; r_out = 0;
			}
			else if ((l_in==1) & (r_in==0))
			{
				state = 0; l_out = 0; r_out = 1;
			}
			else if ((l_in==1) & (r_in==1))
			{
				state = 0; l_out = 0; r_out = 0;
			}	
		}

		else if (state==1)
		{	
		if ((l_in==0) & (r_in==0)) 
		// two paddles closed, left first
			{
	    		state = 1; 

				if (keyer==1) 		// Ultimatic
				{
					l_out = 0; r_out = 1; // change to right
				}
				else if (keyer==2) 	// Single-paddle emulation
				{ 
					l_out = 1; r_out = 0; // keep left
				}
				
		    }
			else if ((l_in==0) & (r_in==1))
			{
				state = 1; l_out = 1; r_out = 0;
			}
			else if ((l_in==1) & (r_in==0))
			{
				state = 0; l_out = 0; r_out = 1;
			}
			else if ((l_in==1) & (r_in==1))
			{
				state = 0; l_out = 0; r_out = 0;
			}	 	
		}
      }
}