#!/usr/bin/python3

import os
import subprocess
pwd="ai"
r1,w1=os.pipe()
r2,w2=os.pipe()
f1=open(os.path.join(pwd,"l1.log"),"w")
f2=open(os.path.join(pwd,"l2.log"),"w")
s1=subprocess.Popen(os.path.join(pwd,"ai1"),stdin=r1,stdout=w2,stderr=f1)
s2=subprocess.Popen(os.path.join(pwd,"ai2"),stdin=r2,stdout=w1,stderr=f2)
if s1.wait()==0 and s2.wait()==0:
	ss="""grep "\(Ret\|Get\)" %s|sed "s/Return: /1,/"|sed "s/>Get: /2,/">%s"""%tuple(os.path.join(pwd,x) for x in ("l1.log","pt.log"))
	os.system(ss)
