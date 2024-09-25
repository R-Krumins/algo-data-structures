import json

def printResident(r):
    str = f"{r['name']} {r['surname']} (tel.nr. {r['phoneNum']})"
    a = r["address"]
    str += f"\nAddress: {a['street']} {a['houseNr']}-{a['apartmentNr']} {a['city']}\n"
    print(str)


def findInCity(city, residents):
    filtered = []
    for resident in residents:
        if(resident["address"]["city"] == city):
            filtered.append(resident)

    return filtered

def findDeptors(city, street, residents):
    filtered = []
    for resident in residents:
        if(resident["rentPaid"] == True): continue

        a = resident["address"]
        if(a["city"] == city and a["street"] == street):
            filtered.append(resident)

    return filtered

with open("residents.json", "r") as file:
    residents = json.load(file)

# Get resulsts and print them
city = "New York"
livingInCity = findInCity(city, residents)

city2 = "New York"
street = "Oak St"
stinky_deptors = findDeptors(city2, street, residents)

#for r in livingInCity: printResident(r)
print(f"There are {len(livingInCity)} residents in {city}")

#for r in stinky_deptors: printResident(r)
print(f"Threre are {len(stinky_deptors)} deptors in {street} {city2}")
