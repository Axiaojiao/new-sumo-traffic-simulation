import pandas as pd
from sumolib.output import parse

# 解析旅行时间数据
tripinfo = parse("tripinfo.xml", "tripinfo")
data = []
for trip in tripinfo:
    data.append({
        "vehicle": trip.id,
        "depart": trip.depart,
        "arrival": trip.arrival,
        "duration": trip.duration,
        "route": trip.route,
    })
df = pd.DataFrame(data)
df.to_csv("travel_times.csv", index=False)