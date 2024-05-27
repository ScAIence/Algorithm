init_time = list(map(int, input().split()))

progress_time = int(input())

init_time_sec = init_time[0]*3600+init_time[1]*60+init_time[2]+progress_time

end_time = list()

end_time.append(init_time_sec//3600%24)
init_time_sec %= 3600
end_time.append(init_time_sec//60)
init_time_sec %= 60
end_time.append(init_time_sec)

for i in end_time:
    print(i, end= " ")