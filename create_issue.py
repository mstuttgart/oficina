from github import Github

# Params
USERNAME = 'mstuttgart'
PASSWORD = ''
REPO = 'mstuttgart/plano-de-estudos'

MILESTONE_TITLE = 'Title'

ISSUE_TITLE = 'Title - Cap. 0%d'
ISSUE_QUANT = 2
ISSUE_LABELS = ['Category: Courses', 'Category: Idea']

# First create a Github instance:
g = Github(USERNAME, PASSWORD)

# Get instance of repo
repo = g.get_repo(REPO)

# Get labels object to list
labels = [repo.get_label(label) for label in ISSUE_LABELS]

# Create a milestone
milestone = repo.create_milestone(MILESTONE_TITLE)

# Create a issue set
for i in range(ISSUE_QUANT):
    issue = repo.create_issue(
        title=ISSUE_TITLE % (i + 1),
        milestone=milestone,
        labels=labels,
        assignee=USERNAME,
    )
