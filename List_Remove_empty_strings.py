str_list = ["Emma", "Jon", "", "Kelly", None, "Eric", ""]
res_list = []
for s in str_list:
    # check for non empty string
    if s:
        res_list.append(s)

print("list before = {0}".format(str_list))
print("list after = {0}".format(res_list))

#using filter function
'''str_list = ["Emma", "Jon", "", "Kelly", None, "Eric", ""]

# use built-in function filter to filter empty value
new_str_list = list(filter(None, str_list))

print("After removing empty strings")
print(new_str_list)'''