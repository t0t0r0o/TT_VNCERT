import time
from bs4 import BeautifulSoup
with open('bt.xml', 'r') as f:
    file = f.read()
soup = BeautifulSoup(file, 'lxml')

ID = []
CREATEAT = []
People = soup.find_all('people')

for people in People:
	ID.append(people.get('id'))
	check = time.gmtime(int(people.attrs['createat'])) # ticks --> struc_time
	CREATEAT.append(""+str(check.tm_mday)+"/"+str(check.tm_mon)+"/"+str(check.tm_year))


NAME = soup.find_all('name')
AGE = soup.find_all("age")

print('-'.center(35, '-'))

print('|'+"ID"+'|' + 'Name'.center(15) + '|' + ' Age ' + '|' + 'CREATEAT'.center(11) + '|')

for i in range(len(NAME)):
    print('-'.center(35, '-'))
    print(
        f'|{ID[i].center(5)}|{NAME[i].text.center(15)}|{AGE[i].text.center(5)}|{CREATEAT[i].center(5)}|')
print('-'.center(35, '-'))