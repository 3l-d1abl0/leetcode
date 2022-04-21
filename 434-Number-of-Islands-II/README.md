
<h2><a href="https://www.lintcode.com/problem/434/description">434 · Number of Islands II</a></h2>


<h3>Medium</h3>
<hr>

<div data-h5="false" class="content-wrapper-32rgvmtTEZlJxhYe-SXar4"><div class="sub-title-3tQamyyYH5-VXCEHKrzgsd with-action-3ISUSOCo8G5-PfWWWyKDb9">Description</div><div class="react-markdown react-markdown-2P3YjvgELb5tvqGDu8Rkkt"><p>Given a n,m which means the row and column of the 2D matrix and an array of pair A( size k). Originally, the 2D matrix is all 0 which means there is only sea in the matrix. The list pair has k operator and each operator has two integer A[i].x, A[i].y means that you can change the grid matrix[A[i].x][A[i].y] from sea to island. Return how many island are there in the matrix after each operator.You need to return an array of size K.</p></div><div data-show="true" class="ant-alert ant-alert-info ant-alert-with-description notice-1ncxxfAmH3X1SpRYMMoH2g"><i aria-label="icon: info-circle" class="anticon anticon-info-circle ant-alert-icon"><svg viewBox="64 64 896 896" focusable="false" class="" data-icon="info-circle" width="1em" height="1em" fill="currentColor" aria-hidden="true"><path d="M512 64C264.6 64 64 264.6 64 512s200.6 448 448 448 448-200.6 448-448S759.4 64 512 64zm0 820c-205.4 0-372-166.6-372-372s166.6-372 372-372 372 166.6 372 372-166.6 372-372 372z"></path><path d="M464 336a48 48 0 1 0 96 0 48 48 0 1 0-96 0zm72 112h-48c-4.4 0-8 3.6-8 8v272c0 4.4 3.6 8 8 8h48c4.4 0 8-3.6 8-8V456c0-4.4-3.6-8-8-8z"></path></svg></i><span class="ant-alert-message"></span><span class="ant-alert-description"><div class="react-markdown react-markdown-2P3YjvgELb5tvqGDu8Rkkt"><p>0 is represented as the sea, 1 is represented as the island. If two 1 is adjacent, we consider them in the same island. We only consider up/down/left/right adjacent.</p></div></span></div></div>



<div data-h5="false" class="content-wrapper-32rgvmtTEZlJxhYe-SXar4"><div class="sub-title-3tQamyyYH5-VXCEHKrzgsd">Example</div><div class="react-markdown react-markdown-2P3YjvgELb5tvqGDu8Rkkt"><p><strong>Example 1:</strong></p>
<pre><div class="markdown-thumbnail-wrapper" style="height: auto; max-height: unset;"><pre style="display: block; overflow-x: auto; background: rgb(43, 43, 43); color: rgb(248, 248, 242); padding: 0.5em;"><code>Input: n = <span style="color: rgb(245, 171, 53);">4</span>, m = <span style="color: rgb(245, 171, 53);">5</span>, A = [[<span style="color: rgb(245, 171, 53);">1</span>,<span style="color: rgb(245, 171, 53);">1</span>],[<span style="color: rgb(245, 171, 53);">0</span>,<span style="color: rgb(245, 171, 53);">1</span>],[<span style="color: rgb(245, 171, 53);">3</span>,<span style="color: rgb(245, 171, 53);">3</span>],[<span style="color: rgb(245, 171, 53);">3</span>,<span style="color: rgb(245, 171, 53);">4</span>]]
Output: [<span style="color: rgb(245, 171, 53);">1</span>,<span style="color: rgb(245, 171, 53);">1</span>,<span style="color: rgb(245, 171, 53);">2</span>,<span style="color: rgb(245, 171, 53);">2</span>]
Explanation:
<span style="color: rgb(245, 171, 53);">0.</span>  <span style="color: rgb(245, 171, 53);">00000</span>
    <span style="color: rgb(245, 171, 53);">00000</span>
    <span style="color: rgb(245, 171, 53);">00000</span>
    <span style="color: rgb(245, 171, 53);">00000</span>
<span style="color: rgb(245, 171, 53);">1.</span>  <span style="color: rgb(245, 171, 53);">00000</span>
    <span style="color: rgb(245, 171, 53);">01000</span>
    <span style="color: rgb(245, 171, 53);">00000</span>
    <span style="color: rgb(245, 171, 53);">00000</span>
<span style="color: rgb(245, 171, 53);">2.</span>  <span style="color: rgb(245, 171, 53);">01000</span>
    <span style="color: rgb(245, 171, 53);">01000</span>
    <span style="color: rgb(245, 171, 53);">00000</span>
    <span style="color: rgb(245, 171, 53);">00000</span>
<span style="color: rgb(245, 171, 53);">3.</span>  <span style="color: rgb(245, 171, 53);">01000</span>
    <span style="color: rgb(245, 171, 53);">01000</span>
    <span style="color: rgb(245, 171, 53);">00000</span>
    <span style="color: rgb(245, 171, 53);">00010</span>
<span style="color: rgb(245, 171, 53);">4.</span>  <span style="color: rgb(245, 171, 53);">01000</span>
    <span style="color: rgb(245, 171, 53);">01000</span>
    <span style="color: rgb(245, 171, 53);">00000</span>
    <span style="color: rgb(245, 171, 53);">00011</span></code></pre></div></pre>
<p><strong>Example 2:</strong></p>
<pre><div class="markdown-thumbnail-wrapper" style="height: auto; max-height: unset;"><pre style="display: block; overflow-x: auto; background: rgb(43, 43, 43); color: rgb(248, 248, 242); padding: 0.5em;"><code>Input: n = <span style="color: rgb(245, 171, 53);">3</span>, m = <span style="color: rgb(245, 171, 53);">3</span>, A = [[<span style="color: rgb(245, 171, 53);">0</span>,<span style="color: rgb(245, 171, 53);">0</span>],[<span style="color: rgb(245, 171, 53);">0</span>,<span style="color: rgb(245, 171, 53);">1</span>],[<span style="color: rgb(245, 171, 53);">2</span>,<span style="color: rgb(245, 171, 53);">2</span>],[<span style="color: rgb(245, 171, 53);">2</span>,<span style="color: rgb(245, 171, 53);">1</span>]]
Output: [<span style="color: rgb(245, 171, 53);">1</span>,<span style="color: rgb(245, 171, 53);">1</span>,<span style="color: rgb(245, 171, 53);">2</span>,<span style="color: rgb(245, 171, 53);">2</span>]</code></pre></div></pre></div></div>