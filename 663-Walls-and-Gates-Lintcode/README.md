
<h2><a href="https://www.lintcode.com/problem/663/">663 · Walls and Gates</a></h2>


<h3>Medium</h3>
<hr>

<div data-h5="false" class="content-wrapper-32rgvmtTEZlJxhYe-SXar4"><div class="sub-title-3tQamyyYH5-VXCEHKrzgsd with-action-3ISUSOCo8G5-PfWWWyKDb9">Description</div><div class="react-markdown react-markdown-2P3YjvgELb5tvqGDu8Rkkt"><p>You are given a m x n 2D grid initialized with these three possible values.</p>
<p><code>-1</code>  - A wall or an obstacle.<br>
<code>0</code>   - A gate.<br>
<code>INF</code> - Infinity means an empty room. We use the value <code>2^31 - 1 = 2147483647</code> to represent INF as you may assume that the distance to a gate is less than <code>2147483647</code>.<br>
Fill each empty room with the distance to its nearest gate. If it is impossible to reach a <code>Gate</code>, that room should remain filled with <code>INF</code></p></div></div>



<div data-h5="false" class="content-wrapper-32rgvmtTEZlJxhYe-SXar4"><div class="sub-title-3tQamyyYH5-VXCEHKrzgsd">Example</div><div class="react-markdown react-markdown-2P3YjvgELb5tvqGDu8Rkkt"><p><strong>Example1</strong></p>
<pre><div class="markdown-thumbnail-wrapper" style="height: auto; max-height: unset;"><pre style="display: block; overflow-x: auto; background: rgb(43, 43, 43); color: rgb(248, 248, 242); padding: 0.5em;"><code>Input:
[[<span style="color: rgb(245, 171, 53);">2147483647</span>,<span style="color: rgb(245, 171, 53);">-1</span>,<span style="color: rgb(245, 171, 53);">0</span>,<span style="color: rgb(245, 171, 53);">2147483647</span>],[<span style="color: rgb(245, 171, 53);">2147483647</span>,<span style="color: rgb(245, 171, 53);">2147483647</span>,<span style="color: rgb(245, 171, 53);">2147483647</span>,<span style="color: rgb(245, 171, 53);">-1</span>],[<span style="color: rgb(245, 171, 53);">2147483647</span>,<span style="color: rgb(245, 171, 53);">-1</span>,<span style="color: rgb(245, 171, 53);">2147483647</span>,<span style="color: rgb(245, 171, 53);">-1</span>],[<span style="color: rgb(245, 171, 53);">0</span>,<span style="color: rgb(245, 171, 53);">-1</span>,<span style="color: rgb(245, 171, 53);">2147483647</span>,<span style="color: rgb(245, 171, 53);">2147483647</span>]]
Output:
[[<span style="color: rgb(245, 171, 53);">3</span>,<span style="color: rgb(245, 171, 53);">-1</span>,<span style="color: rgb(245, 171, 53);">0</span>,<span style="color: rgb(245, 171, 53);">1</span>],[<span style="color: rgb(245, 171, 53);">2</span>,<span style="color: rgb(245, 171, 53);">2</span>,<span style="color: rgb(245, 171, 53);">1</span>,<span style="color: rgb(245, 171, 53);">-1</span>],[<span style="color: rgb(245, 171, 53);">1</span>,<span style="color: rgb(245, 171, 53);">-1</span>,<span style="color: rgb(245, 171, 53);">2</span>,<span style="color: rgb(245, 171, 53);">-1</span>],[<span style="color: rgb(245, 171, 53);">0</span>,<span style="color: rgb(245, 171, 53);">-1</span>,<span style="color: rgb(245, 171, 53);">3</span>,<span style="color: rgb(245, 171, 53);">4</span>]]

Explanation:
the <span style="color: rgb(245, 171, 53);">2</span>D grid <span style="color: rgb(220, 198, 224);">is</span>:
INF  <span style="color: rgb(245, 171, 53);">-1</span>  <span style="color: rgb(245, 171, 53);">0</span>  INF
INF INF INF  <span style="color: rgb(245, 171, 53);">-1</span>
INF  <span style="color: rgb(245, 171, 53);">-1</span> INF  <span style="color: rgb(245, 171, 53);">-1</span>
  <span style="color: rgb(245, 171, 53);">0</span>  <span style="color: rgb(245, 171, 53);">-1</span> INF INF
the answer <span style="color: rgb(220, 198, 224);">is</span>:
  <span style="color: rgb(245, 171, 53);">3</span>  <span style="color: rgb(245, 171, 53);">-1</span>   <span style="color: rgb(245, 171, 53);">0</span>   <span style="color: rgb(245, 171, 53);">1</span>
  <span style="color: rgb(245, 171, 53);">2</span>   <span style="color: rgb(245, 171, 53);">2</span>   <span style="color: rgb(245, 171, 53);">1</span>  <span style="color: rgb(245, 171, 53);">-1</span>
  <span style="color: rgb(245, 171, 53);">1</span>  <span style="color: rgb(245, 171, 53);">-1</span>   <span style="color: rgb(245, 171, 53);">2</span>  <span style="color: rgb(245, 171, 53);">-1</span>
  <span style="color: rgb(245, 171, 53);">0</span>  <span style="color: rgb(245, 171, 53);">-1</span>   <span style="color: rgb(245, 171, 53);">3</span>   <span style="color: rgb(245, 171, 53);">4</span></code></pre></div></pre>
<p><strong>Example2</strong></p>
<pre><div class="markdown-thumbnail-wrapper" style="height: auto; max-height: unset;"><pre style="display: block; overflow-x: auto; background: rgb(43, 43, 43); color: rgb(248, 248, 242); padding: 0.5em;"><code>Input:
<span style="color: rgb(171, 227, 56);">[[0,-1],[2147483647,2147483647]]</span>
Output:
<span style="color: rgb(171, 227, 56);">[[0,-1],[1,2]]</span></code></pre></div></pre></div></div>