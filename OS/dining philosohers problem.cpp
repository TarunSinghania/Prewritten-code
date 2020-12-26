while(TRUE) 
{
    wait(stick[i]);
    /* 
        mod is used because if i=5, next 
        chopstick is 1 (dining table is circular)
    */
    wait(stick[(i+1) % 5]);  
                    
    /* eat */
    signal(stick[i]);
    
    signal(stick[(i+1) % 5]); 
    /* think */
}