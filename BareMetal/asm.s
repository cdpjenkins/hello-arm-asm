.text
.global get_el
.global out_word
.global in_word
.global out_word

get_el:
    mrs x0, currentel
    lsr x0, x0, #2
    ret
