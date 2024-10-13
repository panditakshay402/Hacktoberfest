#importing the necessary libraries
import cv2
import os
import matplotlib.pyplot as plt
import random
import numpy as np
import tensorflow
from keras.models import Sequential
from keras.layers import Conv2D,MaxPooling2D,Flatten,Dense

#initializing the file path and the names of the classes
Directory=r"D:\car logo detection\Train"
Category=['hyundai','lexus','mazda','mercedes','opel','skoda','toyota','volkswagen']

#preprocessing the data
im=128
data=[]
for category in Category:
    folder=os.path.join(Directory,category)
    label=Category.index(category)
    for img in os.listdir(folder):
        img_path=os.path.join(folder,img)
        img_arr=cv2.imread(img_path)
        img_arr=cv2.resize(img_arr,(im,im))
        data.append([img_arr,label])

#seperating the data into features and labels
X=[]
y=[]

for features,labels in data:
    X.append(features)
    y.append(labels)

#shuffling the data to improve the model's performance
random.shuffle(data)

#converting the data into numpy arrays
X=np.array(X)
y=np.array(y)

X=X/255

X.shape

#convolutional neural network with "relu" activation function in the nodes and "softmax" activation function in the 8 output nodes
model=Sequential()

model.add(Conv2D(64,(3,3),activation="relu"))
model.add(MaxPooling2D((2,2)))

model.add(Conv2D(64,(3,3),activation="relu"))
model.add(MaxPooling2D((2,2)))

model.add(Flatten())

model.add(Dense(128,input_shape=X.shape[1:],activation="relu"))
model.add(Dense(8,activation="softmax"))

#adding the optimizer and the loss function
model.compile(optimizer="adam",loss="sparse_categorical_crossentropy",metrics=['accuracy'])

#training the model
model.fit(X,y,epochs=5,validation_split=0.1)

#saving the model
model.save("car_logo_detection1.h5")
