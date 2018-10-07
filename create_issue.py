from github import Github

# Params
USERNAME = 'mstuttgart'
PASSWORD = ''
REPO = 'mstuttgart/plano-de-estudos'

MILESTONE_TITLE = 'Milestone Name'
ISSUE_TITLE = 'Issue Name - 0%d'

LABELS = ['Category: Courses', 'Category: Idea']

ISSUE_QUANT = 3

# First create a Github instance:
g = Github(USERNAME, PASSWORD)

# Get instance of repo
repo = g.get_repo(REPO)

# Get labels object to list
labels = [repo.get_label(label) for label in LABELS]

# Create a milestone
milestone = repo.create_milestone(MILESTONE_TITLE)

# Create a issue set
for i in range(ISSUE_QUANT):
    repo.create_issue(title=ISSUE_TITLE % (i + 1), milestone=milestone, labels=labels, assignee=USERNAME)
