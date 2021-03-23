" My vim config

set nocompatible             " be iMproved, required
set number
set autochdir				 " start at current directory file
set cursorline
set tabstop=4
set shiftwidth=4
set encoding=UTF-8
set termguicolors
filetype off                 " required

set rtp+=~/.vim/bundle/Vundle.vim

call vundle#begin()

Plugin 'VundleVim/Vundle.vim'

" Add plugins here

Plugin 'preservim/nerdtree'
Plugin 'preservim/nerdcommenter'
Plugin 'Valloric/YouCompleteMe'
Plugin 'vim-airline/vim-airline'
Plugin 'vim-airline/vim-airline-themes'
Plugin 'ayu-theme/ayu-vim'
Plugin 'octol/vim-cpp-enhanced-highlight'

call vundle#end()            " required

filetype plugin indent on    " required

nnoremap <silent> <C-t> :NERDTreeToggle <CR>
let ayucolor='mirage'
let g:ycm_global_ycm_extra_conf = '/home/wolfx/.vim/bundle/YouCompleteMe/third_party/ycmd/cpp/ycm/.ycm_extra_conf.py'
let g:ycm_enable_diagnostic_signs = 0
let g:airline_theme='ayu'
set completeopt-=preview
colorscheme ayu

