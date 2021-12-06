import json, sys

with open('/home/rohanhh2/cs225final/data/raw.json') as json_data:
    data = json.load(json_data)
    
    p = data['playlists']
    i = 0
    for playlist in data['playlists']: 
        data['playlists'][i].pop('duration_ms', None)
        data['playlists'][i].pop('collaborative', None)
        data['playlists'][i].pop('modified_at', None)
        data['playlists'][i].pop('num_albums', None)
        data['playlists'][i].pop('num_artists', None)
        data['playlists'][i].pop('num_edits', None)
        data['playlists'][i].pop('num_followers', None)
        for track in playlist['tracks']:
            track.pop('duration_ms', None)
            track.pop('album_name', None)
            track.pop('album_uri', None)
            track.pop('artist_name', None)
            track.pop('artist_uri', None)
            track.pop('pos', None)
            track.pop('track_uri', None)
        i+= 1
    
    for j in range(len(p)):
        if (j > 10):
            p.pop(11)
            
open("output.json", "w").write(
    json.dumps(data, sort_keys=True, indent=4, separators=(',',': '))
)