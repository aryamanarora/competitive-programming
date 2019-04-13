t = gets.chomp.to_i
for i in (1..t)
  n = gets.chomp
  s = gets.chomp.split('')
  print "Case #"
  print i
  print ": "
  for c in s
    if c == 'S'
      print 'E'
    else
      print 'S'
    end
  end
  puts
end