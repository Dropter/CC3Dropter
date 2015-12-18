# Description
Files generated from uavobjgenerator Tool from OpenPilot.

# Usage
We get the UAV Object ID openning the *.h file and looking for the definition of it.  
For example:  
  - #define ACCELSTATE_OBJID 0xAD3C0E06  
</br >
And also the key elements from that object (struct):  
  ```
  typedef struct {  
    float x;  
    float y;  
    float z;  
} __attribute__((packed)) AccelStateDataPacked;  
```  
</br >
Then we define this elements in our UAVTalk.h file.  
</br>
For more details please watch the next video:  
 -  
