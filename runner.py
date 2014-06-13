#!/usr/bin/python3

import os
import subprocess
r1,w1=os.pipe()
r2,w2=os.pipe()
f1=open("l1.log","w")
f2=open("l2.log","w")
s1=subprocess.Popen("ai1.exe",stdin=r1,stdout=w2,stderr=f1)
s2=subprocess.Popen("ai2.exe",stdin=r2,stdout=w1,stderr=f2)
if s1.wait()==0 and s2.wait()==0:
	os.system("""grep "\(Ret\|Get\)" l1.log|sed "s/Return: /1,/"|sed "s/>Get: /2,/">pt.log""")
