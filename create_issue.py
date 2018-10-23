from github import Github

# Params
USERNAME = 'mstuttgart'
PASSWORD = ''
REPO = 'mstuttgart/plano-de-estudos'

MILESTONE_TITLE = 'Titulo milestone'

ISSUE_TITLE = 'Titulo - 0%d'
ISSUE_QUANT = 1
ISSUE_LABELS = ['Category: Books', 'Category: Idea']


# First create a Github instance:
g = Github(USERNAME, PASSWORD)

# Get instance of repo
repo = g.get_repo(REPO)

# Get labels object to list
labels = [repo.get_label(label) for label in ISSUE_LABELS]

# Create a milestone
milestone = repo.create_milestone(MILESTONE_TITLE)

comment = ''

# Create a issue set
for i in range(ISSUE_QUANT):
    issue = repo.create_issue(
        title=ISSUE_TITLE % (i + 1),
        milestone=milestone,
        labels=labels,
        assignee=USERNAME,
    )
    comment += '#' + issue.id + "\n"

# Case estejamos criando issues para livros
# Criamos uma issue adicional para anexar a
# milestone de 12 livros em um ano
if 'Category: Books' in labels:
    # Create a milestone
    milestone = repo.get_milestone(1)
    repo.create_issue(
        title=MILESTONE_TITLE,
        body=comment,
        milestone=milestone,
        labels=labels,
        assignee=USERNAME,
    )

