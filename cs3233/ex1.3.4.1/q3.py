import datetime

a = datetime.date(2010, 8, 9)
b = datetime.date.today()
print(a.strftime("%a"), (b - a).days)