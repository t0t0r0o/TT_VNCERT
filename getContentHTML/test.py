from urllib.request import urlopen
from bs4 import BeautifulSoup
import requests
import time
import pandas as pd


URL = 'https://www.premierleague.com/'

page=requests.get(URL+'/clubs')

soup = BeautifulSoup(page.content,'html.parser')

clubTags = soup.find_all('a', {'class': 'indexItem'})

clubs = []

for tag in clubTags:
	clubURL = URL +tag['href']
	clubURL = clubURL.replace("overview", "squad")
	clubs.append(clubURL)
playerOverviews = []

for club in clubs:
	while(True):
		try:
			clubPage = requests.get(club)
			clubSoup = BeautifulSoup(clubPage.content, 'html.parser')
			playerTags = clubSoup.find_all('a', {'class': 'playerOverviewCard'})

			for tag in playerTags:
				playerURL = URL +tag['href']
				playerOverviews.append(playerURL)
			break;
		except:
			time.sleep(5)
			continue


#Trich xuat du lieu

names = []
numbers = []
ages = []
clubs = []
heights = []
weights = []
nations = []
positions = []
validPositions = ['Goalkeeper', 'Midfielder', 'Defender', 'Forward']

for playerURL in playerOverviews:
	playerPage = requests.get(playerURL)
	playerSoup = BeautifulSoup(playerPage.content, 'html.parser')
	# scrape names
	try:
		playerName = playerSoup.find_all('div',{'class':'name'})
		playerName = playerName[0].text.strip()
		names.append(playerName)
	except:
		names.append(None)
	# scrape clubs
	try:
		playerClub = playerSoup.find_all('td', {'class':'team'})
		playerClub = playerClub[0].find_all('span', {'class':'short'})
		playerClub = playerClub[0].text.strip()
		clubs.append(playerClub)
	except:
		clubs.append(None)
    # scrape positions
	try:
		temp = playerSoup.find_all('div',{'class':'info'})
		tempPosition = temp[1].text.strip()
		if tempPosition in validPositions:
			playerPosition = tempPosition
		else:
			tempPosition = temp[0].text.strip()
			playerPosition = tempPosition
		positions.append(playerPosition)
	except:
		positions.append(None)
	#scrape numbers
	try:
		playerNumber = playerSoup.find_all('div', {'class':'number'})
		playerNumber = playerNumber[0].text.strip()
		numbers.append(playerNumber)
	except:
		numbers.append(None)
    #scrape ages
	try:
		playerAge = playerSoup.find_all('ul',{"class":'pdcol2'})
		playerAge = playerAge[0].find_all('span',{"class":"info--light"})
		playerAge = playerAge[0].text.strip().replace('(','').replace(')','')
		ages.append(playerAge)
	except:
		ages.append(None)
    #scrape heights
	try:
		playerPhysical = playerSoup.find_all('ul',{'class': 'pdcol3'})
		playerPhysical = playerPhysical[0].find_all('div',{'class':'info'})
		playerHeight = playerPhysical[0].text.strip()
		heights.append(playerHeight)
	except:
		heights.append(None)
    #scrape weights
	try:
		playerPhysical = playerSoup.find_all('ul',{'class': 'pdcol3'})
		playerPhysical = playerPhysical[0].find_all('div',{'class':'info'})
		playerWeight = playerPhysical[1].text.strip()
		weights.append(playerWeight)
	except:
		weights.append(None)
    #scrape nationalities
	try:
		playerNation = playerSoup.find_all('ul',{'class':'pdcol1'})
		playerNation = playerNation[0].find_all('div',{'class':'info'})
		playerNation = playerNation[0].text.strip()
		nations.append(playerNation)
	except:
		nations.append(None)

d = {
	'Name': names,
	'Position': positions,
	'Number': numbers,
	'Club': clubs,
	'Nationities': nations,
	'Age': ages,
	'Height (cm)': heights,
	'Weight (kg)': weights
}

playerOverview = pd.DataFrame(d)

playerOverview.dropna(axis = 0, inplace = True)
playerOverview.reset_index(drop = True, inplace = True)


loans = []

for i in range(len(playerOverview)):
	if '(Loan)' in playerOverview['Club'][i]:
		loans.append('Yes')
		playerOverview['Club'][i] = playerOverview['Club'][i].replace('(Loan)','')
	else:
		loans.append('No')
playerOverview['On Loan'] = loans


for i in range(len(playerOverview)):
	height = playerOverview['Height (cm)'][i]
	newHeight = ''
	for letter in height:
		if not(letter.isalpha()):
			newHeight+=letter
	playerOverview['Height (cm)'][i] = newHeight

	weight = playerOverview['Weight (kg)'][i]
	newWeight = ''
	for letter in weight:
		if not(letter.isalpha()):
			newWeight += letter
	playerOverview['Weight (kg)'][i] = newWeight


playerOverview['Age'] = playerOverview['Age'].astype(int)
playerOverview['Height (cm)'] = playerOverview['Height (cm)'].astype(int)
playerOverview['Weight (kg)'] = playerOverview['Weight (kg)'].astype(int)



playerOverview.to_csv(r'playerOverviews1.csv')



