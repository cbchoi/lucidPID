import matplotlib.pyplot as plt

P_data = []
PD_data = []
PI_data = []
PID_data = []

fp = open("../test_P.dat")
for line in fp:
	P_data.append(line)
fp.close()

fp = open("..//test_PI.dat")
for line in fp:
	PI_data.append(line)
fp.close()

fp = open("../test_PD.dat")
for line in fp:
	PD_data.append(line)
fp.close()

fp = open("../test_PID.dat")
for line in fp:
	PID_data.append(line)
fp.close()


plt.figure(1)
plt.subplot(411)
plt.plot(P_data)
plt.ylabel('P Controller')

plt.subplot(412)
plt.plot(PI_data)
plt.ylabel('PI Controller')

plt.subplot(413)
plt.plot(PD_data)
plt.ylabel('PD Controller')

plt.subplot(414)
plt.plot(PID_data)
plt.ylabel('PID Controller')

plt.show()
