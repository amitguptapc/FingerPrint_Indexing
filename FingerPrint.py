#!/usr/bin/env python
# coding: utf-8

# In[1]:


import cv2
from matplotlib import pyplot as plt
import numpy as np


# In[2]:


img = cv2.imread('finger.jpg')


# In[3]:


plt.imshow(img)
plt.show()


# In[4]:


oneDImg = img[:,:,0]
oneDImg = oneDImg.reshape((-1,))
print(oneDImg.shape)
print(oneDImg)


# In[5]:


for i in range(oneDImg.shape[0]):
    if oneDImg[i] == 255:
        oneDImg[i] = 0
    else:
        oneDImg[i] = 1
print(oneDImg)
print(oneDImg.shape)


# In[6]:


for i in range(oneDImg.shape[0]):
    print(oneDImg[i],end=" ")


# In[7]:


with open("imageMatrix.txt",'w') as f:
    for i in oneDImg:
        f.write(str(i))
    f.write('+')


# In[ ]:




