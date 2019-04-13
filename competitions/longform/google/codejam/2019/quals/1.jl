t = parse(Int, chomp(readline()))

for i = 1:t
  n = chomp(readline())
  a = Char[]
  b = Char[]
  for c in n
    if c == '4'
      push!(a, '2')
      push!(b, '2')
    elseif length(b) == 0
      push!(a, c)
    else
      push!(a, c)
      push!(b, '0')
    end
  end
  print("Case #", i, ": ")
  for c in a
    print(c)
  end
  print(' ')
  if length(b) == 0
    push!(b, '0')
  end
  for c in b
    print(c)
  end
  println()
end