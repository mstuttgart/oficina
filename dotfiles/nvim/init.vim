" Vim-Plug core
"******:***********************************************************************
let vimplug_exists=expand('~/.config/nvim/autoload/plug.vim')
if has('win32')&&!has('win64')
  let curl_exists=expand('C:\Windows\Sysnative\curl.exe')
else
  let curl_exists=expand('curl')
endif

if !filereadable(vimplug_exists)
  if !executable(curl_exists)
    echoerr "You have to install curl or first install vim-plug yourself!"
    execute "q!"
  endif
  echo "Installing Vim-Plug..."
  echo ""
  silent exec "!"curl_exists" -fLo " . shellescape(vimplug_exists) . " --create-dirs https://raw.githubusercontent.com/junegunn/vim-plug/master/plug.vim"
  let g:not_finish_vimplug = "yes"

  autocmd VimEnter * PlugInstall
endif

" Required:
call plug#begin(expand('~/.config/nvim/plugged'))

" vim-plug pluggin
let g:plugged_home = '~/.config/nvim/plugged'

"------------ Plugins list ----------------

" Plugins List
call plug#begin(g:plugged_home)

  " UI related
  Plug 'vim-airline/vim-airline'
  Plug 'vim-airline/vim-airline-themes'
  
  " NERDTree plugin
  Plug 'scrooloose/nerdtree'
  Plug 'unkiwii/vim-nerdtree-sync'

  " Git plugins
  Plug 'airblade/vim-gitgutter'
  Plug 'tpope/vim-fugitive'

  " Themes
  Plug 'morhetz/gruvbox'
  Plug 'ajmwagar/vim-deus'
  Plug 'nordtheme/vim'
  Plug 'sainnhe/everforest'
  Plug 'altercation/vim-colors-solarized'
  Plug 'ayu-theme/ayu-vim'

  " Multi language support
  Plug 'sheerun/vim-polyglot'
  
  " Better Visual Guide
  Plug 'Yggdroot/indentLine'

  " Comment code
  Plug 'scrooloose/nerdcommenter'

  " Auto close chars like '(', '{', '[' and ""
  Plug 'jiangmiao/auto-pairs'
  
  " ---> closing XML tags <---
  Plug 'alvan/vim-closetag'

  " ---> files on which to activate tags auto-closing <---
  let g:closetag_filenames = '*.html,*.xhtml,*.xml,*.vue,*.phtml,*.js,*.jsx,*.coffee,*.erb'
  
  " ---> closing braces and brackets <---
  Plug 'jiangmiao/auto-pairs'
  
  " enable search Ctrl+P
  Plug 'kien/ctrlp.vim'
  Plug 'nvim-lua/plenary.nvim'
  Plug 'nvim-telescope/telescope.nvim', { 'tag': '0.1.1' }
  Plug 'nvim-treesitter/nvim-treesitter'

  "" Vim-Session
  Plug 'xolox/vim-misc'
  Plug 'xolox/vim-session'
 
  " html
  "" HTML Bundle
  Plug 'hail2u/vim-css3-syntax'
  Plug 'gko/vim-coloresque'
  Plug 'tpope/vim-haml'
  Plug 'mattn/emmet-vim'

  " javascript
  "" Javascript Bundle
  Plug 'jelera/vim-javascript-syntax'
  
  " python
  Plug 'vim-scripts/indentpython.vim'
  Plug 'davidhalter/jedi-vim'
  Plug 'raimon49/requirements.txt.vim', {'for': 'requirements'}
  
 call plug#end()

"------------ General Settings ---------------
"
filetype plugin indent on

" Configurations Part
" UI configuration
syntax on
syntax enable

" Open new split panes to right and bottom, which feels more natural than Vim’s default
set splitbelow
set splitright

" Set encoding
set encoding=utf-8
set fileencoding=utf-8
set fileencodings=utf-8

"" Fix backspace indent
set backspace=indent,eol,start

" Show line number
set number

" Highlight matching [{()}]
set showmatch  

" Important!!
" Apenas para o forest
if has('termguicolors')
  set termguicolors
endif

"let g:solarized_termcolors=256

" set blackground
set background=light

" For better performance
let g:everforest_better_performance = 1

"let ayucolor="light"  " for light version of theme
"let ayucolor="mirage" " for mirage version of theme
"let ayucolor="dark"   " for dark version of theme
"	
" awesome color schem
colorscheme everforest

" expand tabs into spaces
set expandtab

set shiftwidth=4
set softtabstop=0
set tabstop=4
set expandtab

" indent when moving to the next line while writing code
set autoindent
set smartindent

" show cursor line
set cursorline

"" enable hidden buffers
set hidden

" Search configuration
set ignorecase                    " ignore case when searching
set smartcase                     " turn on smartcase
set incsearch

" Highlight all matches
set hlsearch     

" use system clipboard
set clipboard=unnamed

" disable folding
set nofoldenable

" session management
let g:session_directory = "~/.config/nvim/session"
let g:session_autoload = "no"
let g:session_autosave = "no"
let g:session_command_aliases = 1

" Save and exit easier way 
inoremap <C-s> <esc>:wa<cr>                 " save files
nnoremap <C-s> :wa<cr>
inoremap <C-d> <esc>:wqa!<cr>               " save and exit
nnoremap <C-d> :wqa!<cr>

" ------ status bar settings -----------
"

"" Status bar
set laststatus=2

"" Use modeline overrides
set modeline
set modelines=10

set title
set titleold="Terminal"
set titlestring=%F

set statusline=%F%m%r%h%w%=(%{&ff}/%Y)\ (line\ %l\/%L,\ col\ %c)\

if exists("*fugitive#statusline")
  set statusline+=%{fugitive#statusline()}
endif

" --------- leader shortcuts -----------
"

" mapleader keyshortcut
let mapleader = ","

" TABS
noremap <Tab> :tabnext<CR>
noremap <S-Tab> :tabprevious<CR>
nnoremap <C-t> :tabnew<CR>
noremap <C-e> :tabclose<CR>

" No more Arrow keys, deal with it
noremap <Up> <NOP>
noremap <Down> <NOP>
noremap <Left> <NOP>
noremap <Right> <NOP>
noremap <S>k <NOP>

" Comment lines
noremap <Leader>cc 

" open terminaL
map <Leader>tt :terminal<CR>

" close terminal
tnoremap <esc> <c-\><C-N>

" Changes all ocourrences for the text that you have typed
nnoremap <Leader>r :%s///g<Left><Left>
nnoremap <Leader>rc :%s///gc<Left><Left><Left>

xnoremap <Leader>r :s///g<Left><Left>
xnoremap <Leader>rc :s///gc<Left><Left><Left>

" Find files using Telescope command-line sugar.
nnoremap <leader>ff <cmd>Telescope find_files<cr>
nnoremap <leader>fg <cmd>Telescope live_grep<cr>
nnoremap <leader>fb <cmd>Telescope buffers<cr>
nnoremap <leader>fh <cmd>Telescope help_tags<cr>

"" Split
noremap <Leader>h :<C-u>split<CR>
noremap <Leader>v :<C-u>vsplit<CR>


" session management
nnoremap <leader>so :OpenSession<Space>
nnoremap <leader>ss :SaveSession<Space>
nnoremap <leader>sd :DeleteSession<CR>
nnoremap <leader>sc :CloseSession<CR>

"" Set working directory
nnoremap <leader>. :lcd %:p:h<CR>

"------------ Airline Settings ----------------
"
let g:airline_theme = 'everforest'
let g:airline_left_sep	= ''
let g:airline_right_sep = ''

let g:airline#extensions#virtualenv#enabled = 1
let g:airline#extensions#branch#enabled = 1

let g:airline_skip_empty_sections = 1

"let g:airline#extensions#ale#enabled = 1
"let g:airline#extensions#ale#error_symbol = 'E:'
"let g:airline#extensions#ale#warning_symbol = 'W:'
"

" vim-airline
if !exists('g:airline_symbols')
  let g:airline_symbols = {}
endif

if !exists('g:airline_powerline_fonts')
  let g:airline#extensions#tabline#left_sep = ' '
  let g:airline#extensions#tabline#left_alt_sep = '|'
  let g:airline_left_sep          = '▶'
  let g:airline_left_alt_sep      = '»'
  let g:airline_right_sep         = '◀'
  let g:airline_right_alt_sep     = '«'
  let g:airline#extensions#branch#prefix     = '⤴' "➔, ➥, ⎇
  let g:airline#extensions#readonly#symbol   = '⊘'
  let g:airline#extensions#linecolumn#prefix = '¶'
  let g:airline#extensions#paste#symbol      = 'ρ'
  let g:airline_symbols.linenr    = '␊'
  let g:airline_symbols.branch    = '⎇'
  let g:airline_symbols.paste     = 'ρ'
  let g:airline_symbols.paste     = 'Þ'
  let g:airline_symbols.paste     = '∥'
  let g:airline_symbols.whitespace = 'Ξ'
else
  let g:airline#extensions#tabline#left_sep = ''
  let g:airline#extensions#tabline#left_alt_sep = ''

  " powerline symbols
  let g:airline_left_sep = ''
  let g:airline_left_alt_sep = ''
  let g:airline_right_sep = ''
  let g:airline_right_alt_sep = ''
  let g:airline_symbols.branch = ''
  let g:airline_symbols.readonly = ''
  let g:airline_symbols.linenr = ''
endif

"------------ NERDTree Settings ----------------

" NERDTree and nerd_tree_tabs configuration
nnoremap <silent> <F2> :NERDTreeFind<CR>
nnoremap <silent> <F3> :NERDTreeToggle<CR>
nmap <Leader>rr :NERDTreeFocus<cr>R<c-w><c-p>

let g:NERDTreeWinSize=50

let g:NERDTreeIgnore=['node_modules','\.rbc$', '\~$', '\.pyc$', '\.db$', '\.sqlite$', '__pycache__']
"let g:NERDTreeIgnore=['\.rbc$', '\~$', '\.pyc$', '\.db$', '\.sqlite$', '__pycache__']
let g:NERDTreeSortOrder=['^__\.py$', '\/$', '*', '\.swp$', '\.bak$', '\~$']

let g:nerdtree_tabs_focus_on_files=1
let g:NERDTreeMapOpenInTabSilent = '<RightMouse>'

"------------ Specifi files settings Settings ----------------

" Number of visual spaces that a pre-existing tab is equal to.
au BufRead,BufNewFile *py set tabstop=4

" spaces for indents
au BufRead,BufNewFile *.py; set shiftwidth=4
au BufRead,BufNewFile *.py; set expandtab " turn tabs in spaces
au BufRead,BufNewFile *.py; set softtabstop=4 " number of spaces in tab when editing
au BufRead,BufNewFile *.py; set autoindent
au BufRead,BufNewFile *.py; set textwidth=79
au BufRead,BufNewFile *.py; set fileformat=unix

" spaces for indents in javascript, html and css files
au BufRead,BufNewFile *.js,*.html,*.css; set tabstop=2
au BufRead,BufNewFile *.js,*.html,*.css; set softtabstop=2
au BufRead,BufNewFile *.js,*.html,*.css; set shiftwidth=2

" javascript
let g:javascript_enable_domhtmlcss = 1

" jedi-vim
let g:jedi#popup_on_dot = 0
let g:jedi#goto_assignments_command = "<leader>g"
let g:jedi#goto_definitions_command = "<leader>d"
let g:jedi#documentation_command = "K"
let g:jedi#usages_command = "<leader>n"
let g:jedi#rename_command = "<leader>r"
let g:jedi#show_call_signatures = "0"
let g:jedi#completions_command = "<C-Space>"
let g:jedi#smart_auto_mappings = 0


" Syntax highlight
let python_highlight_all = 1

" save buffer auto
au FocusLost * silent! wa

" ----------- Abbreviations ----------------
"

cnoreabbrev W! w!
cnoreabbrev Q! q!
cnoreabbrev Qall! qall!
cnoreabbrev Wq wq
cnoreabbrev Wa wa
cnoreabbrev wQ wq
cnoreabbrev WQ wq
cnoreabbrev W w
cnoreabbrev Q q
cnoreabbrev Qall qall
