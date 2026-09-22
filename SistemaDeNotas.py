#Criação das listas.
nomes = []
notas = []

#Função que cadastra alunos e suas respectivas notas.
def cadastrarAluno(nomes, notas):
  print('====================')
  print('Cadastro de Aluno')
  print('====================')
  nome = input("Informe o nome do aluno: ")
  while True:
    print('--------------------')
    n1 = float(input("Informe a 1º nota do aluno (0 a 10): "))
    n2 = float(input("Informe a 2º nota do aluno (0 a 10): "))
    n3 = float(input("Informe a 3º nota do aluno (0 a 10): "))
    #Esse if garante que a nota informada vai estar entre 0 e 10.
    if n1 >= 0 and n1 <= 10 and n2 >= 0 and n2 <= 10 and n3 >= 0 and n3 <= 10:
      break
    else:
      print("Nota inválida. Informe notas entre 0 e 10.")
  #A função append adiciona o nome do aluno e suas notas nas listas correspondentes.
  nomes.append(nome)
  notas.append((n1, n2, n3))
  print(f"Aluno cadastrado.")

#Função que lista os alunos cadastrados e suas respectivas notas.
def listarAlunos(nomes, notas):
  if len(nomes) == 0:
    print("Nenhum aluno cadastrado.")
    return
  print('====================')
  print("Alunos cadastrados:")
  print('====================')
  #Percorre a lista de nomes e notas, exibindo-os na tela.
  for i in range(len(nomes)):
    print(f"{i + 1}. {nomes[i]} - Nota: {notas[i]}")

#função que calcula a média da turma.
def calcularMedia(notas):
  if len(notas) == 0:
    print("Nenhuma nota registrada.")
    return 0
  soma = 0
  quantidadeNotas = 0
  for notasAluno in notas:
    for nota in notasAluno:
      soma += nota
      quantidadeNotas += 1    
#Armazena a soma das notas e a quantidade de notas para calcular a média.
  media = soma / quantidadeNotas
  print('--------------------')
  print(f"A média da turma é: {media:.2f}")
  return media

#Função que lista os alunos aprovados, ou seja, aqueles que possuem média maior ou igual a 7.
def listarAprovados(nomes, notas):
  if len(nomes) == 0:
    print("Nenhum aluno cadastrado.")
    return
  quantidade = 0
  print('====================')
  print("Alunos aprovados:")
  print('====================')
#Percorre a lista, utiliza a função sum() para somar todas as notas de cada aluno e divide pelo numero de notas registradas.
  for i in range(len(nomes)):
    media = sum(notas[i]) / len(notas[i])
    if media >= 7:
      print(f"{nomes[i]}")
      quantidade += 1
  if quantidade == 0:
    print("Nenhum aluno aprovado.")

#Função que conta a quantidade de alunos aprovados de forma recursiva.
def contarAprovadosRecursivo(notas, indice):
  if indice == len(notas):
      return 0
  mediaAluno = sum(notas[indice]) / len(notas[indice])
  if mediaAluno >= 7:
      return 1 + contarAprovadosRecursivo(notas, indice + 1)
  return contarAprovadosRecursivo(notas, indice + 1)

def buscaSequencial(nomes, notas):
  print('--------------------')
  nomeProcurado = input("Informe o nome do aluno que deseja buscar: ")
  print('--------------------')
  for i in range(len(nomes)):
    if nomes[i].lower() == nomeProcurado.lower():
      print('====================')
      print(f"Aluno encontrado: {nomes[i]} - Nota: {notas[i]}")
      return i
  print("Aluno não encontrado.")
  return -1

def somarNotasRecursiva(notas, indice):
  if indice == len(notas):
      return 0
  somaAluno = sum(notas[indice])
  return somaAluno + somarNotasRecursiva(notas, indice + 1)

def estatisticas(notas):
  if len(notas) == 0:
    print('Nenhuma nota cadastrada.')
    return
  soma = somarNotasRecursiva(notas, 0)
  aprovados = contarAprovadosRecursivo(notas, 0)
  quantidadeNotas = len(notas) * 3
  media = soma / quantidadeNotas
  percentual = (aprovados / len(notas)) * 100
  print('====================')
  print("Estatísticas Complementares:")
  print('====================')
  print(f"Soma das notas: {soma:.2f}")
  print(f"Média da turma: {media:.2f}")
  print(f"Quantidade de aprovados: {aprovados}")
  print(f"Percentual de aprovação: {percentual:.2f}%")


def mediaPorAluno(notas, nomes):
  medias = []
  for nota in notas:
    media = sum(nota) / len(nota)
    medias.append(media)
  print('--------------------')
  print("Médias dos alunos:")
  print('--------------------')
  for i in range(len(medias)):
    print(f"{i + 1}. {nomes[i]} - Média: {medias[i]:.2f}")

def funcionalidadesExtras(nomes, notas):
  while True:
    print('====================')
    print('Funcionalidades Extras')
    print('====================')
    print('S1 - Busca sequencial')
    print('S2 - Estatisticas Complementares')
    print('S3 - Contagem de Aprovados')
    print('S4 - Media por aluno')
    print('S - Voltar ao menu principal')
    opcao2 = input('Escolha uma opção: ').lower()
    if opcao2 == 's1':
      buscaSequencial(nomes, notas)
    elif opcao2 == 's2':
      estatisticas(notas)
    elif opcao2 == 's3':
      aprovados = contarAprovadosRecursivo(notas, 0)
      print('--------------------')
      print(f"Quantidade de aprovados: {aprovados}")
    elif opcao2 == 's4':
      mediaPorAluno(notas, nomes)
    elif opcao2 == 's':
      return
    else: 
      print("Opção inválida.")
      return

while True:
  print('====================')
  print('Sistema de Notas')
  print('====================')
  print('1 - Cadastrar aluno e notas')
  print('2 - Exibir alunos e notas')
  print('3 - Calcular média')
  print('4 - Listar alunos aprovados')
  print('5 - Acessar submenu funcionalidades extras')
  print('0 - Sair')
  opcao = input('Escolha uma opção: ')
  if opcao == '1':
    cadastrarAluno(nomes, notas)
  elif opcao == '2':
    listarAlunos(nomes, notas)
  elif opcao == '3':
    calcularMedia(notas)
  elif opcao == '4':
    listarAprovados(nomes, notas)
  elif opcao == '5':
    funcionalidadesExtras(nomes, notas)
  elif opcao == '0':
    print('Saindo do sistema...')
    break
  else:
    print('Opção inválida. Tente novamente.')
