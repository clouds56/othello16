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
s1.wait()
s2.wait()
f1.close()
f2.close()
